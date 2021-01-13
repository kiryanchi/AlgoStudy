// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 약수의 합
// 시작일 : 2021-01-13
// 종료일 : 2021-01-13
// 코멘트 : 문제는 쉽지만 최적화 아이디어를 떠올리기 힘들었다.
// 최적화 아이디어 : N의 가장 큰 약수는 N을 제외하면 최대 N의 절반인 원리를 이용해 실행횟수를 기존의 절반으로 줄일 수 있을 것 같은데 구현이 잘 안된다.
public class mingiSeo_programmers_12928 {

    private static int Solution(int n) {
        int answer = 0;
        if (n == 0)
            answer = 0;

        if (n == 1)
            answer = 1;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                answer += i;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int n = 0;
        System.out.println(Solution(n));
    }
}
