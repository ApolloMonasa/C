/*************************************************************************
	> File Name: test2.0.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 29 Apr 2025 11:23:20 PM CST
 ************************************************************************/


#include "Bostom.h"

#define DATA 380 //训练样本数目
#define TESTDATA 126 //预测样本数目
#define IN 13 //输入层神经元数目
#define NEURON 100 //隐含层神经元数目
#define OUT 1 //输出层神经元数目
#define TRAINC 40000 //训练次数
#define WALTA 0.1 //权值w的学习率
#define VALTA 0.2 //权值v的学习率

double d_in[DATA][IN]; //训练样本
double d_out[DATA][OUT]; //训练样本对应的输出
double t_in[TESTDATA][IN]; //测试样本
double t_out[TESTDATA][OUT]; //测试样本对应的输出
double pre[TESTDATA][OUT]; //预测样本的实际输出
double v[NEURON][IN]; //输入层到隐含层的权值
double y[NEURON]; //隐含层的输出
double w[OUT][NEURON]; //隐含层到输出层的权值
double Maxin[IN], Minin[IN];//样本输入的最大值和最小值
double Maxout[OUT], Minout[OUT];//样本输出的最大值和最小值
double OutputData[OUT]; //输出层的输出
double dw[OUT][NEURON]; //输出层的权值修正量
double dv[NEURON][IN]; //隐含层的权值修正量
double mse; //均方误差
double rmse; //均方根误差
int offset;//记录文件读取位置


void ReadData() {
	FILE* fp1, * fp2;
	char ch;
	if ((fp1 = fopen("housing.txt", "r")) == NULL) {
		printf("Cannot open the file housing.txt\n");
		exit(0);
	}
	char buff[200];
	//把第一行表头读入buff中
	fgets(buff, sizeof(buff), fp1);

	//读取训练样本
	for (int i = 0; i < DATA; i++) {
		for (int j = 0; j < IN; j++) {
			fscanf(fp1, "%lf", &d_in[i][j]);
		}
		for (int j = 0; j < OUT; j++) {
			fscanf(fp1, "%lf", &d_out[i][j]);
		}
	}
	//标记位置，方便读取测试样本
	offset = ftell(fp1);
	fclose(fp1);
	return;
}

void InitBPNetwork() {
	//initsrand
	srand((unsigned)time(NULL));
	//找到每一维度数据的最大值和最小值
	for (int i = 0; i < IN; i++) {
		Minin[i] = Maxin[i] = d_in[0][i];
		for (int j = 0; j < DATA; j++) {
			Maxin[i] = max(Maxin[i], d_in[j][i]);
			Minin[i] = min(Minin[i], d_in[j][i]);
		}
	}
	//找到输出数据的最大值和最小值
	for (int i = 0; i < OUT; i++) {
		Minout[i] = Maxout[i] = d_out[0][i];
		for (int j = 0; j < DATA; j++) {
			Maxout[i] = max(Maxout[i], d_out[j][i]);
			Minout[i] = min(Minout[i], d_out[j][i]);
		}
	}
	//使用最大最小值归一化方法处理输入数据
	for (int i = 0; i < IN; i++) {
		for (int j = 0; j < DATA; j++) {
			d_in[j][i] = (d_in[j][i] - Minin[i]) / (Maxin[i] - Minin[i]);
		}
	}
	//使用最大最小值归一化方法处理输出数据
	for (int i = 0; i < OUT; i++) {
		for (int j = 0; j < DATA; j++) {
			d_out[j][i] = (d_out[j][i] - Minout[i]) / (Maxout[i] - Minout[i]);
		}
	}
	//初始化输入层到隐藏层的权值
	for (int i = 0; i < NEURON; i++) {
		for (int j = 0; j < IN; j++) {
			//权值范围在[-1,1]之间
			v[i][j] = (double)(rand() % 20000) / 10000 - 1;
			//权值修正量赋值为0
			dv[i][j] = 0;
		}
	}
	//初始化隐含层到输出层的权值
	for (int i = 0; i < OUT; i++) {
		for (int j = 0; j < NEURON; j++) {
			//权值范围在[-1,1]之间
			w[i][j] = (double)(rand() % 20000) / 10000 - 1;
			//权值修正量赋值为0
			dw[i][j] = 0;
		}
	}
}

void ComputO(int var) {
	double sum;//存放累加和
	//计算隐含层每个神经元的输出
	for (int i = 0; i < NEURON; i++) {
		sum = 0;
		for (int j = 0; j < IN; j++) {
			sum += d_in[var][j] * v[i][j];
		}
		y[i] = 1.0 / (1 + exp(-sum));//sigmoid激活函数
	}
	//计算输出层每个神经元的输出
	for (int i = 0; i < OUT; i++) {
		sum = 0;
		for (int j = 0; j < NEURON; j++) {
			sum += y[j] * w[i][j];
		}
		OutputData[i] = 1.0 / (1 + exp(-sum));//sigmoid激活函数
	}
}

void BackUpdata(int var) {
	double t;
	//遍历隐含层的每个神经元
	for (int i = 0; i < NEURON; i++) {
		t = 0;
		//修正隐含层到输出层的权值
		for (int j = 0; j < OUT; j++) {
			dw[j][i] = WALTA * (d_out[var][j] - OutputData[j]) * OutputData[j] * (1 - OutputData[j]) * y[i];
			w[j][i] += dw[j][i];//更新权值
			t += (d_out[var][j] - OutputData[j]) * OutputData[j] * (1 - OutputData[j]) * w[j][i];
		}
		//修正隐含层与输入层的权值
		for (int j = 0; j < IN; j++) {
			dv[i][j] = VALTA * t * y[i] * (1 - y[i]) * d_in[var][j];
			v[i][j] += dv[i][j];//更新权值
		}
	}
}

void TrainBPNetwork() {
	int cnt = 1;//记录训练次数
	do {
		mse = 0;//均方误差设置为0
		//完成所有训练样本的一轮训练
		for (int i = 0; i < DATA; i++) {
			ComputO(i);//前向传播
			BackUpdata(i);//反向传播， 调整权值
			//计算单个样本的误差
			for (int j = 0; j < OUT; j++) {
				double tmp1 = OutputData[j] * (Maxout[0] - Minout[0]) + Minout[0];//计算实际输出
				double tmp2 = d_out[i][j] * (Maxout[0] - Minout[0]) + Minout[0];//计算期望输出
				mse += (tmp1 - tmp2) * (tmp1 - tmp2);//累计均方误差
			}
		}
		mse = mse / DATA * OUT;//计算均方误差
		//每隔1000次训练输出一次均方误差
		if (cnt % 1000 == 0) {
			printf("第%d次训练，均方误差为：%lf\n", cnt, mse);
		}
		cnt++;//训练次数加1
	} while (cnt < TRAINC && mse > 0.0001);//训练次数小于40000次，均方误差大于0.0001
	//训练完成后，输出最终的均方误差
	printf("训练完成，均方误差为：%lf\n", mse);
}

void TestBPNetwork() {
	FILE* fp;
	//读取测试样本，用offset找到文件位置
	if ((fp = fopen("housing.txt", "r")) == NULL) {
		printf("Cannot open the file housing.txt\n");
		exit(0);
	}
	fseek(fp, offset, SEEK_SET);
	//读取预测数据集
	for (int i = 0; i < TESTDATA; i++) {
		for (int j = 0; j < IN; j++) {
			fscanf(fp, "%lf", &t_in[i][j]);
		}
		for (int j = 0; j < OUT; j++) {
			fscanf(fp, "%lf", &t_out[i][j]);
		}
	}
	fclose(fp);
	double sum;
	//预测数据归一化处理
	for (int i = 0; i < IN; i++) {
		for (int j = 0; j < TESTDATA; j++) {
			t_in[j][i] = (t_in[j][i] - Minin[i]) / (Maxin[i] - Minin[i]);
		}
	}
	//计算每一个测试样本的预测结果
	for (int k = 0; k < TESTDATA; k++) {
		//计算隐含层输出
		for (int i = 0; i < NEURON; i++) {
			sum = 0;
			for (int j = 0; j < IN; j++) {
				sum += t_in[k][j] * v[i][j];
			}
			y[i] = 1.0 / (1 + exp(-sum));//sigmoid激活函数
		}
		//计算输出层预测结果
		sum = 0;
		for (int j = 0; j < NEURON; j++) {
			sum += y[j] * w[0][j];
		}
		//预测结果反归一化
		pre[k][0] = 1 / (1 + exp(-1 * sum)) * (Maxout[0] - Minout[0]) + Minout[0];
		//输出预测值和实际值
		printf("第%d个测试样本的预测值为：%lf，实际值为：%lf\n", k + 1, pre[k][0], t_out[k][0]);
	}
	//计算均方根误差
	rmse = 0;
	for (int k = 0; k < TESTDATA; k++) {
		rmse += (pre[k][0] - t_out[k][0]) * (pre[k][0] - t_out[k][0]);
	}
	rmse = sqrt(rmse / TESTDATA);
	//输出均方根误差
	printf("均方根误差为：%lf\n", rmse);
}

int main() {
	ReadData();
	InitBPNetwork();
	TrainBPNetwork();
	TestBPNetwork();
	return 0;
}
