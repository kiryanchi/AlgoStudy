package mingiSeo_programmers;
// 코드명 : AlgoStudy 2021 프로그래머스 해시 level 3 (score : fail)
// 작성자 : 서민기
// 문제명 : 베스트엘범
// 시작일 : 2021-01-09
// 종료일 : 2021-01-10
// 참고 - https://velog.io/@aquarius1997/Algo-HashMap%EA%B3%BC-Comparator%EB%B2%A0%EC%8A%A4%ED%8A%B8%EC%95%A8%EB%B2%94
import java.util.*;

// 1. 장르 별로 2개씩 뽑는다.
// 2. 많이 재생된 장르에 속한 노래를 먼저 수록.
// 3. 장르 내에서 많이 재생된 노래를 먼저 수록.
// 4. 장르 내에서 재생 횟수가 같을 경우 고유 번호가 낮은 노래를 먼저 수록.
// 우선순위 = 많이 재생된 장르 오름차순 > 많이 재생된 노래 오름차순 > (재생횟수 같을 경우) 고유번호 내림차순

//Map 객체에 저장된 전체 객체를 가져오고 싶을 때
//모든 키를 가져오고 싶을 경우 : keySet() 메소드를 사용해 모든 키를 Set 컬렉션으로 가져온다 -> Iterator를 통해 키를 얻고 이때 값은 get()메소드로 얻으면 된다.
//모든 (키, 값) 쌍을 가져오고 싶을 경우 : entrySet() 메소드로 모든 Map.Entry를 Set 컬렉션으로 가져온다 -> Iterator를 통해 getKey()와 getValue()메소드를 통해 키와 값을 얻는다.

public class mingiSeo_programmers_42579 {

    public static void main(String[] args) {
        String[] genres = {"classic", "pop", "classic", "classic", "pop"};
        int[] plays = {500, 600, 150, 800, 2500};
        solution solution = new solution();
        int[] ansArray = solution.solution(genres, plays);
        for(int i=0;i< ansArray.length;i++){
            System.out.print(ansArray[i]+" ");
        }
    }
}

class solution {

    public class Sort_by_playcnt implements Comparable<Sort_by_playcnt> { // 재생횟수 오름차순, 재생횟수 같을경우 고유번호 내림차순으로 정렬설정
        int music_id;
        int play_count;

        public Sort_by_playcnt(int music_id, int play_count) {
            this.music_id = music_id;
            this.play_count = play_count;
        }

        @Override
        public int compareTo(Sort_by_playcnt Pcnt_Sort) {
            if (this.play_count < Pcnt_Sort.play_count) { // 재생횟수가 많을수록 앞으로
                return 1;
            } else if (this.play_count > Pcnt_Sort.play_count) { // 재생횟수가 적으면 뒤로
                return -1;
            } else {
                if (this.music_id < Pcnt_Sort.music_id) {
                    return 1;
                } else if (this.music_id == Pcnt_Sort.music_id) {
                    return 0;
                } else {
                    return -1;
                }
            }
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        HashMap<String, Integer> genres_PlayCount = new HashMap<>(); // K : 장르 , V : 장르 총 재생횟수
        HashMap<String, ArrayList<Sort_by_playcnt>> musicList = new HashMap<>(); // K : 장르 , V : (고유번호, 재생횟수)
        for (int i = 0; i < genres.length; i++) {
            if (genres_PlayCount.containsKey(genres[i])) { // 이미 해시맵에 있는 장르면
                genres_PlayCount.put(genres[i], genres_PlayCount.get(genres[i]) + plays[i]); // 재생횟수를 더한다
            } else { // 없는 장르면
                genres_PlayCount.put(genres[i], i); // 새로 만든다.
                musicList.put(genres[i], new ArrayList<>());
            }
            ArrayList<Sort_by_playcnt> tempList = musicList.get(genres[i]); // 장르별로 리스트 객체를 만들어 넣는다.
            tempList.add(new Sort_by_playcnt(i, plays[i]));
            musicList.put(genres[i], tempList);
        }


        //************* 장르명, 장르별 총 재생수 를 entrySet()으로 가져와 내림차순 정렬 *************//
        List<Map.Entry<String, Integer>> entries = new ArrayList<Map.Entry<String, Integer>>(genres_PlayCount.entrySet());
        Collections.sort(entries, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if (o1.getValue() < o2.getValue()) {
                    return 1;
                } else if (o1.getValue() == o2.getValue()) {
                    return 0;
                } else {
                    return -1;
                }
            }
        });

        ArrayList<Integer> tempAnswer = new ArrayList<>(); // 정답 배열 일시 저장하는 리스트
        String musicGenres = "";
        // 장르를 entry.getKey()로 가져와서 정렬
        for (Map.Entry<String, Integer> entry : entries) {
            musicGenres = entry.getKey();
            ArrayList<Sort_by_playcnt> sortMusicList = musicList.get(musicGenres);
            Collections.sort(sortMusicList);
        // 장르별 2개까지만 뽑기 위한 조건문
            if (sortMusicList.size() < 2) {
                for (int i = 0; i < sortMusicList.size(); i++) {
                    tempAnswer.add(sortMusicList.get(i).music_id);
                }
            } else {
                for (int i = 0; i < 2; i++) {
                    tempAnswer.add(sortMusicList.get(i).music_id);
                }
            }
        }
        // 완성된 임시정답 정답으로 옮기기
        answer = new int[tempAnswer.size()];
        for (int i = 0; i < tempAnswer.size(); i++) {
            answer[i] = tempAnswer.get(i);
        }
        return answer;
    }
}

