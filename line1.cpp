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
    /* 변수 */
    int TC, MC; //TC: Testcase count, MC: Match count (경기 수)
    int t, m; //for 문 사용 위한 임시 변수
    
    double dist; //vector_score에 입력받기 위한 임시 변수들
    int x, y;
    char name[8];
    
    double minDist;
    
    vector<Score> vector_score; //vector type으로 선언된 Score 객체
    
    
    /* Code */
    scanf("%d", &TC); //TC 입력받음
    
    for(t=0; t<TC; t++) {
        char winTeamName[8]; //이긴 팀의 이름
        int winCnt = 0; // 이긴 팀의 점수
        scanf("%d",&MC);
        
        //입력받기
        for(m=0; m<MC; m++) {
            scanf("%d %d %s", &x, &y, name);
            dist = sqrt(pow(x, 2)+pow(y, 2));
            vector_score.push_back(Score(x, y, name, dist));
        }
        
        //sorting
        sort(vector_score.begin(), vector_score.end(), cmpDist);
        
        
        //이긴 팀 알아내기
        Score win = vector_score.front();
        strcpy(winTeamName, win.name);
        

        //최소 거리 알아내기
        vector<Score>::iterator iter;
        for (iter = vector_score.begin(); iter != vector_score.end(); ++iter){
            if(strcmp(iter->name,winTeamName)==0) {}
            else{
                minDist = iter->dist;
                break;
            }
        }
        
        //동점 제외하고 구하기
        for (iter = vector_score.begin(); iter != vector_score.end(); ++iter){
            if( strcmp(iter->name, winTeamName)==0 && iter->dist<minDist )
                winCnt=winCnt+1;
        }
        
        printf("%s %d\n", winTeamName, winCnt);
        vector_score.clear();
    }
    
    return 0;
}