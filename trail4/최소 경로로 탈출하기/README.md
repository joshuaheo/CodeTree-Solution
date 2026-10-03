# [[개념]최소 경로로 탈출하기](https://www.codetree.ai/trails/complete/curated-cards/intro-escape-with-min-distance)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / 가중치가 동일한 그래프에서의 BFS](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

### 개선점

1. `Scanner` 사용  
`Scanner`는 사용이 편하지만 입력량이 많아지면 느릴 수 있다.  
Java 코테에서는 입력이 많은 경우 `BufferedReader + StringTokenizer`를 사용하는 것이 안전하다.  
현재 바로 터득할 부분은 아니지만 추후 알아둘만한 명령어다.

2. 불필요한 `Arrays.fill()`  
`a` 배열을 `1`로 채운 뒤 바로 모든 원소에 입력값을 다시 저장하고 있으므로 초기화 값이 전부 덮어씌워진다.  
따라서 해당 `Arrays.fill()`은 제거해도 된다.

3. `cnt`의 범위  
`cnt`는 `main()` 내부에서만 사용하므로 `static` 필드로 둘 필요가 없다.  
`main()`의 지역 변수로 선언하면 변수의 사용 범위를 줄일 수 있다.
