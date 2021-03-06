/*
算法思想：
建立 N*N 的数组S，
如果存在ij使得 A[i] == B[j] 则 S[i][j] = 1 否则 S[i][j] = 0
然后按行统计该行仅有1个数字的行数
因为只能改B中的一个数字，一般仅需要将行数+2即可

---但是当行数为N时，即初始为最佳配对集合时，能不能a经b中的某个数i改为自身?
---不可以，只能修改为无关数，所以此时N-1
*/

/*
优化算法：
不使用二维数组而是使用一维数组S[N] = {0}
如果存在ij使得 A[i] == B[j] 则 S[i]+=1 否则S[i]+=0
最后判断S[i] == 1的个数
*/

/*
运行时间：4ms

占用内存：376k
*/

#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> array;
    int N;

public:
    Solution(int N, vector<int> A, vector<int> B);
    int slove();
    ~Solution();
};

Solution::Solution(int N, vector<int> A, vector<int> B)
    : N(N)
    , array(N, 0) // 初始化二维数组array
{
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                array[i] += 1;
                if (array[i] > 1) {
                    // 不必继续计算
                    break;
                }
            }
        }
    }
}

int Solution::slove()
{
    int count = 0;
    for (vector<int>::iterator i = array.begin(), e = array.end(); i != e; i++) {
        if (*i == 1) {
            count++;
        }
    }
    count += 2;
    return ((count > N) ? N - 1 : count);
}

Solution::~Solution()
{
}

int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    Solution s(N, A, B);
    cout << s.slove() << endl;
    return 0;
}