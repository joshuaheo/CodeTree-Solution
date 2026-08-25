# [[챌린지]빙하](https://www.codetree.ai/trails/complete/curated-cards/challenge-glacier)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / BFS 탐색](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 어려움 |
| 경험치 | 90 XP |

## 개선점 및 배운 점

### 1. BFS 시작점도 `visit` 처리

초기 외부 물 탐색을 시작할 때 `(0, 0)`을 큐에 넣었지만 방문 처리를 하지 않았다.

```cpp
f.push({0, 0});
q.push({0, 0});
```

다음과 같이 시작점도 바로 방문 처리하는 것이 좋다.

```cpp
f.push({0, 0});
q.push({0, 0});
visit[0][0] = 1;
```

시작점을 방문 처리하지 않으면 인접한 칸을 탐색한 뒤 `(0, 0)`이 다시 큐에 들어갈 수 있다.  
정답에는 영향을 주지 않지만 불필요한 중복 탐색이 발생한다.

---

## 풀이 방식

일반적인 풀이에서는 매 시간마다 `(0, 0)`에서 BFS를 다시 시작하여 현재 외부와 연결된 물 영역을 찾는다.

이번 코드에서는 `visit`을 한 번 생성한 뒤 계속 유지하고, 이미 외부 물로 확인한 영역은 다시 탐색하지 않았다.

```cpp
vector<vector<int>> visit(n, vector<int>(m, 0));
```

`q`에는 새롭게 외부 물이 된 위치를 저장하고, `f`를 실제 BFS 탐색용 큐로 사용했다.

```cpp
queue<pair<int, int>> q; // 다음 탐색의 시작점
queue<pair<int, int>> f; // 현재 BFS 탐색용
```

빙하가 녹으면 해당 위치를 새로운 외부 물로 저장한다.

```cpp
v[tempr][tempc] = 0;
q.push({tempr, tempc});
visit[tempr][tempc] = 1;
cnt--;
```

따라서 매 시간 전체 외부 영역을 처음부터 다시 탐색하는 대신,

```text
기존 외부 물 기억
→ 인접한 빙하를 녹임
→ 새롭게 외부 물이 된 영역만 탐색
→ 다음 시간으로 전달
```

하는 방식으로 구현했다.

일반적인 BFS 풀이보다 상태 관리가 조금 복잡하지만, 이미 탐색한 외부 물 영역을 반복해서 탐색하지 않는다는 차이가 있다.
