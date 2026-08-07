# [[챌린지]2명의 도둑](https://www.codetree.ai/trails/complete/curated-cards/challenge-two-thieves)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / Backtracking / K개 중 하나를 N번 선택하기(Simple)](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 어려움 |
| 경험치 | 90 XP |

## 기억할 점

- 각 구간에서 선택 가능한 부분집합을 탐색해 최대 제곱합을 구한다.
- 전체 집합에서 원소를 제거하는 방식도 가능하지만, 제거 순서가 달라 같은 부분집합을 중복 방문할 수 있다.
- 중복을 없애려면 각 원소를 순서대로 선택/미선택하는 방식이 깔끔하다.
- 모든 값이 양수이므로 합이 제한 이하가 된 순간, 더 제거하면 가치가 작아져 탐색을 종료해도 된다. (가지치기)
- `vector<int> q(m)`은 0인 원소를 이미 `m`개 생성하며, 이때 push_back하면 앞에 0인 원소가 들어간다.
- `clear()`는 `size`를 0으로 만들며, 남은 `capacity`는 이후 `push_back()`에서 재사용된다. push_back은 size기준이다.
- 마지막 구간에서는 `x + m`이 배열 범위를 넘지 않는지 확인해야 한다.
