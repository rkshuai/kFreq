/*        author: hsner(rmshuai@126.com)
 *      fileName: remark.cpp
 *    createtime: 2017-05-12 00:03:50
 *  fileDescribe: 
 */
#include "remark.h"
MostFreq::MostFreq(const vector<char>& strArray , const int& kNum):strArray(strArray), kNum(kNum){}
int MostFreq::quick(vector<int>& a, vector<char>& b, const int& first, const int& last) {
	int bounds = a[first];
	int L = first;
	int R = last;
	while(L < R) {
		while(a[L]>=bounds && L<R) ++L;
		while(a[R]<bounds  && first<R) --R;
		if(L<R) {
			swap(a[L], a[R]);
			swap(b[L], b[R]);
		}
	}
	if(a[R]>bounds) {
		swap(a[first], a[R]);
		swap(b[first], b[R]);
	}
	return R;
}
void MostFreq::findMax(vector<int>& a,vector<char>& b, const int& first, const int& last, const int& freq) {
	int posi = quick(a, b, first, last);
	int temp = posi - first + 1;
	if(temp == freq) 
		return;
	else if(temp < freq)
		findMax(a, b, posi+1, last, freq-temp);
	else 
		findMax(a, b, first, posi-1, freq);
}
void MostFreq::getFreq() {
	map<char, int>  mFreq;
	map<char, int>::const_iterator mapIter;
	vector<char> v1;
	vector<int> v2;
	vector<char>::const_iterator vecIter;
	int len = -1;
	int num = strArray.size();
	for(int i=0; i<num; ++i)
		mFreq[strArray[i]]++;
	for (map<char, int>::const_iterator mapIter = mFreq.begin(); mapIter != mFreq.end(); ++mapIter) {
		v1.push_back(mapIter->first);
		v2.push_back(mapIter->second);
		len++;
	}
	findMax(v2, v1, 0, len, kNum);
	cout<<"出现"<<kNum<<"次以上的字符为: ";
	for(int i=0; i<kNum; ++i)
		cout<<char(v1[i])<<' ';
	cout<<endl;
}

