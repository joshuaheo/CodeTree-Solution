# [[챌린지]돌 잘 치우기](https://www.codetree.ai/trails/complete/curated-cards/challenge-clear-stones-well)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / BFS 탐색](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 80 XP |

## 조합 선택 `for`문 가지치기

### 현재 버전

현재 돌을 선택하는 경우와 선택하지 않는 경우로 나누어 재귀를 진행했다.

```cpp
select.push_back(start);
selecting(select, start + 1, stone, v);
select.pop_back();

if (m - select.size() < stone.size() - start)
{
    selecting(select, start + 1, stone, v);
}
```

### 추천 버전

```cpp
for (int i = start;
     i <= stone.size() - (m - select.size());
     i++)
{
    select.push_back(i);
    selecting(select, i + 1, stone, v);
    select.pop_back();
}
```

### 변경 이유

조합에서는 현재 위치를 **선택 / 미선택**으로 나누기보다,  
`start` 이후에서 **다음으로 선택할 원소를 직접 고르는 방식**으로 구현할 수 있다.

`i + 1`을 다음 `start`로 넘기기 때문에 이미 선택한 위치보다 뒤의 원소만 선택하게 되어, 순서만 다른 중복 조합이 생성되지 않는다.

### 가지치기

```cpp
stone.size() - (m - select.size())
```

는 **현재 상태에서 필요한 개수를 모두 채울 수 있는 마지막 선택 위치**를 의미한다.

예를 들어 돌이 8개이고 4개를 선택해야 할 때,

```cpp
select.size() == 0
```

이라면 아직 4개가 필요하므로

```text
8 - 4 = 4
```

0-based 기준 `i = 4`까지만 첫 번째 원소로 선택할 수 있다.

`i = 5`부터 선택하면 뒤에 남은 원소를 모두 골라도 4개를 채울 수 없으므로 처음부터 탐색하지 않는다.

즉,

```cpp
i <= stone.size() - (m - select.size())
```

로 반복문의 범위를 제한해 **완성될 수 없는 조합은 재귀 호출 전에 제거한다.**
