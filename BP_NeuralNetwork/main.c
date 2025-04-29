/*************************************************************************
	> File Name: main.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 29 Apr 2025 11:04:35 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h> // 用于 memcpy (虽然没直接用，但包含通常是好习惯)

// --- 宏定义 ---
#define DATA 380      // 训练样本数目 (波士顿房价通常 506 总数，这里假设训练集大小)
#define TESTDATA 126  // 测试样本数目 (506 - 380 = 126)
#define IN 13         // 输入层神经元数目 (特征数)
#define NEURON 40     // 隐含层神经元数目 (可调整)
#define OUT 1         // 输出层神经元数目 (房价)
#define TRAINC 40000  // 最大训练次数 (Epochs)
#define STOP_MSE 0.0001 // 停止训练的 MSE 阈值 (归一化空间)

// --- 超参数 ---
#define INIT_WALTA 0.02   // 输出层初始学习率 (建议调小)
#define INIT_VALTA 0.04   // 隐含层初始学习率 (建议调小)
#define L2_LAMBDA 0.0001  // L2 正则化系数 (需要调整)
#define LR_DECAY_RATE 0.9995 // 学习率衰减率 (可调整)
#define LR_DECAY_STEP 100    // 每多少次迭代衰减一次学习率 (可调整)

// --- 全局变量 ---
// 数据存储
double d_in[DATA][IN];         // 训练样本输入 (归一化后)
double d_out[DATA][OUT];        // 训练样本输出 (归一化后)
double t_in[TESTDATA][IN];     // 测试样本输入 (归一化后)
double t_out[TESTDATA][OUT];    // 测试样本期望输出 (原始值)
double pre[TESTDATA][OUT];     // 测试样本的预测输出 (反归一化后)

// 网络参数
double v[NEURON][IN];      // 输入层到隐含层的权值
double bias_v[NEURON];     // 隐含层的偏置项
double w[OUT][NEURON];     // 隐含层到输出层的权值
double bias_w[OUT];        // 输出层的偏置项

// 网络中间状态
double y[NEURON];          // 隐含层的输出
double OutputData[OUT];    // 输出层的输出 (归一化)

// 归一化参数
double Maxin[IN], Minin[IN];     // 样本输入的最大值和最小值
double Maxout[OUT], Minout[OUT]; // 样本输出的最大值和最小值

// 性能指标
double mse;                // 训练过程中的均方误差 (归一化空间)
double rmse;               // 测试集上的均方根误差 (原始空间)

// 文件读取辅助
int offset;

// --- 工具函数 ---
// 简单的 Fisher-Yates shuffle 算法 (打乱索引)
void shuffle_indices(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            // 从 i 到 n-1 随机选一个元素与 i 交换
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// --- 数据读取 ---
void ReadData() {
    FILE* fp1;
    if ((fp1 = fopen("housing.txt", "r")) == NULL) {
        perror("错误：无法打开 housing.txt 文件");
        exit(EXIT_FAILURE);
    }

    char buff[256]; // 增加缓冲区大小以防万一
    // 跳过第一行表头
    if (fgets(buff, sizeof(buff), fp1) == NULL) {
         fprintf(stderr, "错误：无法读取 housing.txt 的表头\n");
         fclose(fp1);
         exit(EXIT_FAILURE);
    }

    // 读取训练样本
    printf("正在读取训练数据 (%d 个样本)...\n", DATA);
    for (int i = 0; i < DATA; i++) {
        for (int j = 0; j < IN; j++) {
            if (fscanf(fp1, "%lf", &d_in[i][j]) != 1) {
                 fprintf(stderr, "错误：读取训练数据输入时出错 (样本 %d, 特征 %d)\n", i, j);
                 fclose(fp1);
                 exit(EXIT_FAILURE);
            }
        }
        for (int j = 0; j < OUT; j++) {
             if (fscanf(fp1, "%lf", &d_out[i][j]) != 1) {
                 fprintf(stderr, "错误：读取训练数据输出时出错 (样本 %d, 输出 %d)\n", i, j);
                 fclose(fp1);
                 exit(EXIT_FAILURE);
             }
        }
        // 跳过行尾换行符（如果存在）
        int c;
        while ((c = fgetc(fp1)) != '\n' && c != EOF);
    }

    // 标记测试数据开始的位置
    offset = ftell(fp1);
    if (offset == -1) {
         perror("错误：获取文件位置失败");
         fclose(fp1);
         exit(EXIT_FAILURE);
    }
    printf("训练数据读取完毕。\n");
    fclose(fp1);
}

// --- 网络初始化与数据预处理 ---
void InitBPNetwork() {
    srand((unsigned)time(NULL)); // 初始化随机数种子

    // 1. 计算训练数据的最大最小值 (用于归一化)
    printf("正在计算归一化参数...\n");
    for (int i = 0; i < IN; i++) {
        Minin[i] = Maxin[i] = d_in[0][i];
        for (int j = 1; j < DATA; j++) {
            if (d_in[j][i] > Maxin[i]) Maxin[i] = d_in[j][i];
            if (d_in[j][i] < Minin[i]) Minin[i] = d_in[j][i];
        }
    }
    for (int i = 0; i < OUT; i++) {
        Minout[i] = Maxout[i] = d_out[0][i];
        for (int j = 1; j < DATA; j++) {
            if (d_out[j][i] > Maxout[i]) Maxout[i] = d_out[j][i];
            if (d_out[j][i] < Minout[i]) Minout[i] = d_out[j][i];
        }
         printf("  输出 %d: Min=%.4f, Max=%.4f\n", i, Minout[i], Maxout[i]);
    }

    // 2. 归一化训练数据 (Min-Max scaling)
    printf("正在归一化训练数据...\n");
    // 归一化输入数据
    for (int i = 0; i < IN; i++) {
        double range = Maxin[i] - Minin[i];
        if (fabs(range) < 1e-9) { // 检查除零风险 (使用 fabs 处理负范围可能性)
            printf("警告：输入特征 %d 的最大值和最小值相同 (%f)，将归一化为 0。\n", i, Maxin[i]);
            for (int j = 0; j < DATA; j++) {
                d_in[j][i] = 0.0;
            }
        } else {
            for (int j = 0; j < DATA; j++) {
                d_in[j][i] = (d_in[j][i] - Minin[i]) / range;
            }
        }
    }
    // 归一化输出数据
    for (int i = 0; i < OUT; i++) {
        double range = Maxout[i] - Minout[i];
         if (fabs(range) < 1e-9) {
            printf("警告：输出 %d 的最大值和最小值相同 (%f)，将归一化为 0。\n", i, Maxout[i]);
             for (int j = 0; j < DATA; j++) {
                 d_out[j][i] = 0.0;
             }
        } else {
            for (int j = 0; j < DATA; j++) {
                 d_out[j][i] = (d_out[j][i] - Minout[i]) / range;
            }
        }
    }

    // 3. 初始化权重和偏置
    printf("正在初始化网络权重和偏置...\n");
    // 输入层 -> 隐含层 (Xavier/Glorot 初始化)
    double bound_v = sqrt(6.0 / (IN + NEURON));
    for (int i = 0; i < NEURON; i++) {
        bias_v[i] = 0.0; // 初始化偏置为 0
        for (int j = 0; j < IN; j++) {
            v[i][j] = ((double)rand() / RAND_MAX) * 2.0 * bound_v - bound_v;
        }
    }
    // 隐含层 -> 输出层 (Xavier/Glorot 初始化)
    double bound_w = sqrt(6.0 / (NEURON + OUT));
     for (int i = 0; i < OUT; i++) {
        bias_w[i] = 0.0; // 初始化偏置为 0
        for (int j = 0; j < NEURON; j++) {
            w[i][j] = ((double)rand() / RAND_MAX) * 2.0 * bound_w - bound_w;
        }
    }
    printf("网络初始化完成。\n");
}

// --- 前向传播 ---
// 计算给定输入样本的网络输出 (结果存储在全局 OutputData)
void ComputO(int index, double input_data[][IN]) {
    double sum;
    // 计算隐含层输出 y[i]
    for (int i = 0; i < NEURON; i++) {
        sum = bias_v[i]; // 加入偏置
        for (int j = 0; j < IN; j++) {
            sum += input_data[index][j] * v[i][j];
        }
        y[i] = 1.0 / (1.0 + exp(-sum)); // Sigmoid 激活函数
    }
    // 计算输出层输出 OutputData[i]
    for (int i = 0; i < OUT; i++) {
        sum = bias_w[i]; // 加入偏置
        for (int j = 0; j < NEURON; j++) {
            sum += y[j] * w[i][j];
        }
        OutputData[i] = 1.0 / (1.0 + exp(-sum)); // Sigmoid 激活函数
    }
}

// --- 反向传播与参数更新 ---
// 根据当前样本误差更新权重和偏置
void BackUpdata(int index, double current_walta, double current_valta) {
    double delta_o[OUT];    // 输出层误差项 (gradient * activation_derivative)
    double delta_h[NEURON]; // 隐含层误差项
    double error_sum;       // 用于计算隐含层误差的反向传播和

    // 1. 计算输出层误差项 delta_o
    for (int j = 0; j < OUT; j++) {
        // 误差 = (期望输出 - 实际输出)
        // Sigmoid 导数 = output * (1 - output)
        delta_o[j] = (d_out[index][j] - OutputData[j]) * OutputData[j] * (1.0 - OutputData[j]);
    }

    // 2. 更新输出层权重 w 和偏置 bias_w (含 L2 正则化)
    for (int j = 0; j < OUT; j++) {
        // 更新偏置 bias_w[j] (通常不对偏置应用 L2 正则化)
        bias_w[j] += current_walta * delta_o[j];
        // 更新权重 w[j][i]
        for (int i = 0; i < NEURON; i++) {
            // 梯度 = delta_o[j] * y[i]
            // L2 惩罚项 = L2_LAMBDA * w[j][i]
            // 更新 = 学习率 * (梯度 - L2惩罚项) --> 注意：这里是梯度上升，所以符号是 +
            // 或者写成: w = w + lr * delta - lr * lambda * w = w * (1 - lr*lambda) + lr * delta (Weight Decay形式)
            // 这里采用梯度下降形式推导出的更新规则，直接在梯度上减去惩罚项的导数（lambda * w)
             w[j][i] += current_walta * (delta_o[j] * y[i] - L2_LAMBDA * w[j][i]);
        }
    }

    // 3. 计算隐含层误差项 delta_h
    for (int i = 0; i < NEURON; i++) {
        error_sum = 0.0;
        // 将输出层的误差项加权反向传播
        for (int j = 0; j < OUT; j++) {
            error_sum += delta_o[j] * w[j][i];
        }
        // 乘以隐含层激活函数的导数
        delta_h[i] = error_sum * y[i] * (1.0 - y[i]);
    }

    // 4. 更新隐含层权重 v 和偏置 bias_v (含 L2 正则化)
    for (int i = 0; i < NEURON; i++) {
        // 更新偏置 bias_v[i]
        bias_v[i] += current_valta * delta_h[i];
        // 更新权重 v[i][j]
        for (int j = 0; j < IN; j++) {
             // 梯度 = delta_h[i] * d_in[index][j]
             v[i][j] += current_valta * (delta_h[i] * d_in[index][j] - L2_LAMBDA * v[i][j]);
        }
    }
}

// --- 训练网络 ---
void TrainBPNetwork() {
    int epoch = 0; // 使用 epoch 计数更清晰
    double current_walta = INIT_WALTA;
    double current_valta = INIT_VALTA;

    // 用于数据打乱的索引数组
    int* indices = (int*)malloc(DATA * sizeof(int));
    if (indices == NULL) {
        perror("错误：无法为索引分配内存");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < DATA; ++i) {
        indices[i] = i;
    }

    printf("\n--- 开始训练 ---\n");
    printf("最大训练次数: %d\n", TRAINC);
    printf("初始学习率 (W): %.4f, (V): %.4f\n", current_walta, current_valta);
    printf("L2 正则化系数: %.5f\n", L2_LAMBDA);
    printf("学习率衰减率: %.4f (每 %d 迭代)\n", LR_DECAY_RATE, LR_DECAY_STEP);
    printf("停止 MSE 阈值: %.5f\n", STOP_MSE);

    do {
        mse = 0.0; // 每个 epoch 开始时重置累计误差

        // 1. 数据打乱 (Shuffle)
        shuffle_indices(indices, DATA);

        // 2. 学习率衰减 (基于当前 epoch)
        // 可以选择在每个epoch开始时更新，或保持原来的基于总迭代次数
        // current_walta = INIT_WALTA * pow(LR_DECAY_RATE, (double)epoch / LR_DECAY_STEP); // 基于 Epoch
        // current_valta = INIT_VALTA * pow(LR_DECAY_RATE, (double)epoch / LR_DECAY_STEP);
        // 或者保持基于总迭代次数 cnt 的衰减方式，如果 TRAINC 代表总迭代而非 epoch
        // current_walta = INIT_WALTA * pow(LR_DECAY_RATE, (double)epoch * DATA / LR_DECAY_STEP); // 近似基于总迭代
        // current_valta = INIT_VALTA * pow(LR_DECAY_RATE, (double)epoch * DATA / LR_DECAY_STEP);

        // 这里选择在每个 epoch 开始时按步长衰减 (如果需要更平滑，可以用上面的 pow 公式)
        if (epoch > 0 && epoch % LR_DECAY_STEP == 0) {
             current_walta *= LR_DECAY_RATE;
             current_valta *= LR_DECAY_RATE;
             // 防止学习率过小 (可选)
             if(current_walta < 1e-7) current_walta = 1e-7;
             if(current_valta < 1e-7) current_valta = 1e-7;
        }


        // 3. 遍历打乱后的训练数据
        for (int i = 0; i < DATA; i++) {
            int current_index = indices[i]; // 获取当前处理的样本索引

            // 前向传播
            ComputO(current_index, d_in);

            // 反向传播与更新
            BackUpdata(current_index, current_walta, current_valta);

            // 累加当前样本的平方误差 (在归一化空间计算)
            for (int j = 0; j < OUT; j++) {
                double error = d_out[current_index][j] - OutputData[j];
                mse += error * error;
            }
        }

        // 4. 计算当前 epoch 的平均 MSE
        mse = mse / (DATA * OUT); // 平均到每个样本的每个输出维度

        // 5. 输出训练信息 (每隔一定 epoch 输出一次)
        if ((epoch + 1) % 100 == 0) { // 每 100 个 epoch 输出一次
             printf("Epoch %5d: MSE = %lf, LR_W = %.6f, LR_V = %.6f\n",
                    epoch + 1, mse, current_walta, current_valta);
        }

        epoch++; // Epoch 计数加 1

    } while (epoch < TRAINC && mse > STOP_MSE); // 检查停止条件

    printf("--- 训练完成 ---\n");
    printf("总共训练 %d 个 Epoch。\n", epoch);
    printf("最终训练集 MSE (归一化空间): %lf\n", mse);
    free(indices); // 释放内存
}

// --- 测试网络 ---
void TestBPNetwork() {
    FILE* fp;
    printf("\n--- 开始测试 ---\n");

    // 1. 读取测试数据
    printf("正在读取测试数据 (%d 个样本)...\n", TESTDATA);
    if ((fp = fopen("housing.txt", "r")) == NULL) {
        perror("错误：无法重新打开 housing.txt 文件进行测试");
        exit(EXIT_FAILURE);
    }
    // 定位到测试数据开始处
    if (fseek(fp, offset, SEEK_SET) != 0) {
         perror("错误：无法定位到测试数据起始位置");
         fclose(fp);
         exit(EXIT_FAILURE);
    }

    char buff[256]; // 用于跳过可能的空行或行尾符

    for (int i = 0; i < TESTDATA; i++) {
        for (int j = 0; j < IN; j++) {
             if (fscanf(fp, "%lf", &t_in[i][j]) != 1) {
                 fprintf(stderr, "错误：读取测试数据输入时出错 (样本 %d, 特征 %d)\n", i, j);
                 fclose(fp);
                 exit(EXIT_FAILURE);
             }
        }
         for (int j = 0; j < OUT; j++) {
             // 直接读取原始的目标值用于后续比较
             if (fscanf(fp, "%lf", &t_out[i][j]) != 1) {
                 fprintf(stderr, "错误：读取测试数据输出时出错 (样本 %d, 输出 %d)\n", i, j);
                 fclose(fp);
                 exit(EXIT_FAILURE);
             }
         }
        // 跳过行尾换行符
        int c;
        while ((c = fgetc(fp)) != '\n' && c != EOF);
         if (c == EOF && i < TESTDATA - 1) {
              fprintf(stderr, "警告：测试数据文件可能提前结束 (样本 %d)\n", i);
              // 可能需要调整 TESTDATA 的值或检查文件
              break;
         }
    }
    fclose(fp);
    printf("测试数据读取完毕。\n");

    // 2. 归一化测试输入数据 (使用训练集的 Min/Max)
    printf("正在归一化测试输入数据...\n");
    for (int i = 0; i < IN; i++) {
        double range = Maxin[i] - Minin[i];
        if (fabs(range) < 1e-9) {
            for (int j = 0; j < TESTDATA; j++) {
                t_in[j][i] = 0.0; // 与训练时处理方式一致
            }
        } else {
            for (int j = 0; j < TESTDATA; j++) {
                t_in[j][i] = (t_in[j][i] - Minin[i]) / range;
            }
        }
    }

    // 3. 对每个测试样本进行预测并计算误差
    printf("正在进行预测并计算 RMSE...\n");
    double total_squared_error = 0.0;
    for (int k = 0; k < TESTDATA; k++) {
        // 使用训练好的网络进行前向传播 ( ComputO 使用 t_in )
        // 注意 ComputO 会修改全局变量 y 和 OutputData
        ComputO(k, t_in); // ComputO 现在需要知道使用哪个输入数组

        // 反归一化预测结果 (OutputData 是归一化后的预测值)
        for (int j = 0; j < OUT; j++) {
             double range_out = Maxout[j] - Minout[j];
             if (fabs(range_out) < 1e-9) {
                 pre[k][j] = Minout[j]; // 如果训练输出范围为0，预测也应该是该常数
             } else {
                 pre[k][j] = OutputData[j] * range_out + Minout[j];
             }
             // 累加平方误差 (使用反归一化后的预测值 pre 和原始目标值 t_out)
             double error = pre[k][j] - t_out[k][j];
             total_squared_error += error * error;

             // (可选) 输出每个样本的预测值和实际值
             // if (k < 10) { // 只打印前 10 个看看
             //    printf("  样本 %3d: 预测值 = %.4f, 实际值 = %.4f\n", k + 1, pre[k][j], t_out[k][j]);
             // }
        }
    }

    // 4. 计算均方根误差 (RMSE)
    if (TESTDATA > 0) {
        rmse = sqrt(total_squared_error / (TESTDATA * OUT));
        printf("--- 测试完成 ---\n");
        printf("测试集均方根误差 (RMSE): %lf\n", rmse);
    } else {
        printf("--- 测试完成 ---\n");
        printf("没有测试数据，无法计算 RMSE。\n");
    }
}


// --- 主函数 ---
int main() {
    ReadData();         // 读取数据
    InitBPNetwork();    // 初始化网络和预处理数据
    TrainBPNetwork();   // 训练网络
    TestBPNetwork();    // 测试网络性能

    return 0;
}
