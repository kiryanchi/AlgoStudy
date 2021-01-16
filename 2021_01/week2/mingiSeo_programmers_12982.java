// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 예산
// 시작일 : 2021-01-16
// 종료일 : 2021-01-16
// 코맨트 : 굉장히 쉬운 문제였다.

import java.util.Arrays;

public class mingiSeo_programmers_12982 {
    public static void main(String[] args){
        //int[] d = {1,3,2,5,4};
        //int budget=9;
        //3
        int[] d = {2,2,3,3};
        int budget=10;
        //4
        System.out.println(solution(d,budget));
    }
    /* 요청한 예산의 합 <= 총예산 -> 모든 부서 지원가능
    *  요청한 예산의 합 <= 총예산 -> 가장 낮은 예산부터 지원
    *  */

    public static int solution(int[] d, int budget){
        int answer = 0, d_sum=0;
        for(int i=0;i<d.length;i++){
            d_sum+=d[i];
        }
        if(d_sum<=budget){
            answer=d.length;
        }
        if(d_sum>budget){
            d_sum=0;
            Arrays.sort(d);
            for(int i=0;i<d.length;i++){
                if(d_sum>budget){
                    answer=i-1;
                    break;
                }
                if(d_sum==budget){
                    answer=i;
                    break;
                }
                d_sum+=d[i];
            }
        }
        return answer;
    }
}
