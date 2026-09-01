# [[챌린지]나이트](https://www.codetree.ai/trails/complete/curated-cards/challenge-knight-movements)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / 가중치가 동일한 그래프에서의 BFS](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

## BFS에서 목적지 확인 위치

BFS에서는 큐에서 현재 위치를 꺼낸 직후 목적지인지 확인하는 방식이 깔끔하다.

```cpp
int row = q.front().first;
int col = q.front().second;
q.pop();

if (row == dr && col == dc)
{
    flag = true;
    break;
}
```

이후 목적지가 아니라면 주변 위치를 탐색한다.

```cpp
for (int i = 0; i < 8; i++)
{
    int nr = row + mr[i];
    int nc = col + mc[i];

    pushing(q, visit, nr, nc);
}
```

### 이유

큐에 들어온 좌표는 이미 경계 검사와 방문 검사를 통과한 위치이므로, **큐에서 꺼낸 좌표를 기준으로 목적지를 확인하면 탐색 흐름이 단순해진다.**

또한 시작점이 목적지인 경우도 첫 번째 `q.front()`에서 바로 확인할 수 있어 별도의 예외 처리가 필요하지 않다.

```text
큐에서 현재 위치 꺼내기
→ 목적지인지 확인
→ 아니라면 주변 위치 탐색
```

BFS에서는 가능하면 **현재 노드를 꺼낸 직후 목적지 여부를 확인하는 습관**을 들이면 코드를 단순하게 유지하기 좋다.

