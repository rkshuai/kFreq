/*        author: hsner(shuai1.ren@changhong.com)
 *      fileName: remark.h
 *    createtime: 2017-05-11 23:49:04
 *  fileDescribe: 
 *  	Given a array of char, return the k most frequent elements
 *  	For example,
 *  	Given ['1','1','1','2','2','3'] and k = 2, return ['1','2'].
 *  	If the array is empty , return the empty array.
 *  	Note:
 *  	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 *  	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class MostFreq {
	public:
		MostFreq(const vector<char>& strArray, const int& kNum);
		int quick(vector<int>& a, vector<char>& b, const int& first, const int& last);
		void findMax(vector<int>& a,vector<char>& b, const int& first, const int& last, const int& freq);
		void getFreq();
	private:
		vector<char> strArray;
		int kNum;
};

