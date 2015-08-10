#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber1(vector<int>& nums) {
        int nums_size = nums.size();
        int i,k;
        int res = 0;
        for(k = 0; k < 32; k++) {
            int one_count = 0;
            int zero_count = 0;
            for(i=0;i<nums_size;i++) {
                if (((nums[i]>>k) & 1)) one_count++;
                else zero_count++;
            }
            if (one_count % 3) {
                res = (res | (1<<k));
            }
        }
        return res;
    }
    int singleNumber2(vector<int>& nums) {
        int nums_size = nums.size();
        int i,one,two,three;
        one=two=three=0;
        for (i = 0; i < nums_size; i ++) {
            three = two & nums[i];  //�Ѿ����������Σ���������һ��
            two = two | one&nums[i]; //������1���ֳ�����1�Σ��ڼ�����ǰ�Ѿ�������2�εģ�Ϊ�µĳ�����2�ε�
            one = one | nums[i]; //������1��
            //������3�ε������1��2��ȫ��Ĩȥ,��Ϊֻ�г�������ʱ���ſ���Ĩ����
            two = two & (~three);
            one = one & (~three);
        }
        return one;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
