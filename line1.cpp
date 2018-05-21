#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Score{
public:
    int x, y;
    double dist;
    char name[8];
    
    Score() {}
    
    Score(int x, int y, char n[8], double d) {
        this->x = x;
        this->y = y;
        strcpy(this->name, n);
        this->dist = d;
    }
    
    void print() {
        printf("%d %d %f %s\n", x, y, dist, name);
    }
};

bool cmpDist(const Score &a, const Score &b){
    return a.dist < b.dist;
}


int main(int argc, const char * argv[]) {
    /* ���� */
    int TC, MC; //TC: Testcase count, MC: Match count (��� ��)
    int t, m; //for �� ��� ���� �ӽ� ����
    
    double dist; //vector_score�� �Է¹ޱ� ���� �ӽ� ������
    int x, y;
    char name[8];
    
    double minDist;
    
    vector<Score> vector_score; //vector type���� ����� Score ��ü
    
    
    /* Code */
    scanf("%d", &TC); //TC �Է¹���
    
    for(t=0; t<TC; t++) {
        char winTeamName[8]; //�̱� ���� �̸�
        int winCnt = 0; // �̱� ���� ����
        scanf("%d",&MC);
        
        //�Է¹ޱ�
        for(m=0; m<MC; m++) {
            scanf("%d %d %s", &x, &y, name);
            dist = sqrt(pow(x, 2)+pow(y, 2));
            vector_score.push_back(Score(x, y, name, dist));
        }
        
        //sorting
        sort(vector_score.begin(), vector_score.end(), cmpDist);
        
        
        //�̱� �� �˾Ƴ���
        Score win = vector_score.front();
        strcpy(winTeamName, win.name);
        

        //�ּ� �Ÿ� �˾Ƴ���
        vector<Score>::iterator iter;
        for (iter = vector_score.begin(); iter != vector_score.end(); ++iter){
            if(strcmp(iter->name,winTeamName)==0) {}
            else{
                minDist = iter->dist;
                break;
            }
        }
        
        //���� �����ϰ� ���ϱ�
        for (iter = vector_score.begin(); iter != vector_score.end(); ++iter){
            if( strcmp(iter->name, winTeamName)==0 && iter->dist<minDist )
                winCnt=winCnt+1;
        }
        
        printf("%s %d\n", winTeamName, winCnt);
        vector_score.clear();
    }
    
    return 0;
}