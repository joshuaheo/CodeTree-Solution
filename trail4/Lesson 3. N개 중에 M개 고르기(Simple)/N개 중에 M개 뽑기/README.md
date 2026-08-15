# [[개념]N개 중에 M개 뽑기](https://www.codetree.ai/trails/complete/curated-cards/intro-n-choose-m)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / Backtracking / N개 중에 M개 고르기(Simple)](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

## 코드 수정 사항

### 1. `start` 매개변수 추가

#### 수정 전

```cpp
void finding(vector<int> &v)
{
    if (v.size() == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
            finding(v);
            v.pop_back();
        }
        return;
    }

    for (int i = v.back() + 1; i <= n; i++)
    {
        v.push_back(i);
        finding(v);
        v.pop_back();
    }
}
```

#### 수정 후

```cpp
void finding(vector<int> &v, int start)
{
    for (int i = start; i <= n; i++)
    {
        v.push_back(i);
        finding(v, i + 1);
        v.pop_back();
    }
}
```

호출 부분도 다음과 같이 변경했다.

```cpp
finding(v, 1);
```

### 수정 이유

기존에는 벡터가 비어 있을 때 `v.back()`을 사용할 수 없기 때문에 첫 번째 숫자를 선택하는 경우를 별도로 처리해야 했다.

`start`를 매개변수로 추가해 현재 재귀에서 선택할 수 있는 최소 숫자를 직접 전달하도록 변경했다.

```cpp
finding(v, i + 1);
```

선택한 숫자의 다음 숫자부터 탐색하므로 오름차순 조합 조건도 그대로 유지된다.

### 정리

기존:

```text
첫 번째 선택 별도 처리
→ 이후 v.back() + 1부터 탐색
```

수정 후:

```text
start부터 탐색
→ 다음 재귀에 i + 1 전달
```

첫 번째 선택을 위한 특수 처리가 사라져 재귀 구조가 더 단순해졌다.
