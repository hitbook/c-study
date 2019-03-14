#include<stdio.h>
int IsSuperPrime(int num);//判断是否为超级素数
int IsPrime(int num);      //判断是否为素数
int SumNumber(int num);   //数字之和是否为素数
int MulityNumber(int num); //数字之积是否为素数
int SquareNumber(int num); //数字平方和是否为素数
int Count(int num[], int n);      //计算超级素数的个数
int Sum(int num[], int n);		   //计算所有超级素数之和
int Max(int num[], int n);		   //获得最大的超级素数
int IsSuperPrime(int num) {

	return IsPrime(num) && SumNumber(num) && MulityNumber(num) && SquareNumber(num);
}
int IsPrime(int num) {//采用枚举法
	if (num <= 1)
		return 0;
	else {
		for (int i = 2; i < num; i++)
			if (num % i == 0)
				return 0;
		return 1;
	}
}
int SumNumber(int num) {
	int temp[10];
	int count = 0;
	while (num) {
		temp[count++] = num % 10;
		num /= 10;
	}
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += temp[i];
	return IsPrime(sum);
}
int MulityNumber(int num) {
	int temp[10];
	int count = 0;
	while (num) {
		temp[count++] = num % 10;
		num /= 10;
	}
	int mulity = 1;
	for (int i = 0; i < count; i++)
		mulity *= temp[i];
	return IsPrime(mulity);
}
int SquareNumber(int num) {
	int temp[10];
	int count = 0;
	while (num) {
		temp[count++] = num % 10;
		num /= 10;
	}
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += temp[i] * temp[i];
	return IsPrime(sum);
}
int Count(int num[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
		if (IsSuperPrime(num[i])){
			count++;
//			printf("%d\n",num[i]);
		}
			
	return count;

}
int Sum(int num[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (IsSuperPrime(num[i]))
			sum += num[i];
	return sum;
}
int Max(int num[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++)
		if (IsSuperPrime(num[i]))
			if (num[i] > max)
				max = num[i];
	return max;
}
int main()
{
	int num[900];
	for (int i = 0; i < 900; i++)
		num[i] = i + 100;
	printf("%d\n", Count(num, 900));
	printf("%d\n", Sum(num, 900));
	printf("%d\n", Max(num, 900));
	return 0;
}
