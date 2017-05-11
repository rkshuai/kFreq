/*        author: hsner(shuai1.ren@changhong.com)
 *      fileName: main.cpp
 *    createtime: 2017-05-12 01:32:20
 *  fileDescribe: 
 */
#include "remark.h"

int main()
{
	const char str[] = {'a','a','a','b','c','c'};
	vector<char> vec;
	char temp;
	int kNum;
	cout<<"请输入字符数组，格式为: 1 1 1 2 2 3"<<endl;
	while((temp=cin.get())!='\n') {
		if(temp==' ') continue;
		vec.push_back(temp);
	}
	cout<<"请输入出现次数最多的K个元素: K = ";
	cin>>kNum;
	MostFreq mostFreq(vec, kNum);
	mostFreq.getFreq();
	return 0;
}
