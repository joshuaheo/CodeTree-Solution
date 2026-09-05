# [[테스트]상한 귤](https://www.codetree.ai/trails/complete/curated-cards/test-oranges-have-gone-bad)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / 가중치가 동일한 그래프에서의 BFS](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 70 XP |

## 코드 추천 수정 사항

### BFS 거리 계산을 `visit + 1` 방식으로 변경

#### 수정 전

```cpp
int size = q.size();
cnt++;

while (size)
{
    ...
    pushing(v, visit, q, row, col, cnt);
    size--;
}
```

같은 시간대의 노드 개수를 `size`로 구분하고, `cnt`를 증가시키며 거리를 저장했다.

#### 수정 후

```cpp
visit[row][col] = visit[r][c] + 1;
```

현재 위치까지 걸린 시간에 `1`을 더해 다음 위치의 시간을 바로 계산한다.

#### 수정 이유

BFS에서는 현재 칸에서 새로 방문하는 인접 칸의 거리가 항상 `현재 거리 + 1`이다.

따라서 별도로 `size`와 `cnt`를 관리하지 않아도 `visit`에 저장된 값을 이용해 거리를 계산할 수 있다.

```text
현재 위치의 거리
→ visit[r][c]

다음 위치의 거리
→ visit[r][c] + 1
```

성능 차이보다는 BFS의 거리 계산 구조를 단순하게 만들고, 별도의 레벨 관리 변수를 줄인다는 장점이 있다.

