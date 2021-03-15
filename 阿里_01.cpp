/*链接：https://www.nowcoder.com/questionTerminal/b82ef1bdd71c4751846aacd412975ff2?toCommentId=8656965
来源：牛客网
*/ 
/*
给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。

请你找到这个数组里第 k 个缺失的正整数。
*/ 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 获取缺失的正整数
     * @param array int整型一维数组 已知数组
     * @param arrayLen int array数组长度
     * @param start int整型 开始数
     * @return int整型
     */
    int getInter(int* array, int arrayLen, int start) {
        sort(array, array + arrayLen);
        int pos = start;
        if(array[0] != 1) {
            pos -= array[0] - 1;
        }
        // 如果缺少的第 k 个数都在 array[0]之前，那start 就是缺少的第 k 个数
        if(pos < 0) {
            return start;
        }
        for(int i = 1; i < arrayLen; i++) {
            while(array[i] > array[i-1] + 1) {
                pos--;
                array[i-1] += 1;
                if(pos == 0) {
                    return array[i-1];
                }
            }
        }
        if(pos > 0) {
            return array[arrayLen-1] + pos;
        }
        return -1;
         
    }
};
