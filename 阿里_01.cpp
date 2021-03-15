/*���ӣ�https://www.nowcoder.com/questionTerminal/b82ef1bdd71c4751846aacd412975ff2?toCommentId=8656965
��Դ��ţ����
*/ 
/*
����һ�� �ϸ��������� ������������ arr ��һ������ k ��

�����ҵ����������� k ��ȱʧ����������
*/ 
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ��ȡȱʧ��������
     * @param array int����һά���� ��֪����
     * @param arrayLen int array���鳤��
     * @param start int���� ��ʼ��
     * @return int����
     */
    int getInter(int* array, int arrayLen, int start) {
        sort(array, array + arrayLen);
        int pos = start;
        if(array[0] != 1) {
            pos -= array[0] - 1;
        }
        // ���ȱ�ٵĵ� k �������� array[0]֮ǰ����start ����ȱ�ٵĵ� k ����
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
