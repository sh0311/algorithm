# [Silver V] 좌표 정렬하기 - 11650 

[문제 링크](https://www.acmicpc.net/problem/11650) 

처음에 runtime error 뜸( 이차원 배열 말고 배열을 2개 생성했고 sort함수 안쓰고 버블 정렬 이용함). 2차원 배열 사용하고 sort()쓰면 이차원 배열도 오름차순으로 정렬해줌! 
### 성능 요약

메모리: 46628 KB, 시간: 4448 ms

### 분류

정렬

### 제출 일자

2023년 10월 10일 15:23:11

### 문제 설명

<p>2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 x<sub>i</sub>와 y<sub>i</sub>가 주어진다. (-100,000 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.</p>

### 출력 

 <p>첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.</p>

