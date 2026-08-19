# [[테스트]최소 점프 횟수](https://www.codetree.ai/trails/complete/curated-cards/test-min-num-of-jumps)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / Backtracking / K개 중 하나를 N번 선택하기(Conditional)](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 70 XP |
## 코드 수정 사항

### 1. 최소 점프 횟수 비교 조건 수정

#### 수정 전

```cpp
if (v[location-i].second <= v[location].second)
{
    continue;
}
```

#### 수정 후

```cpp
if (v[location-i].second <= v[location].second + 1)
{
    continue;
}
```

#### 수정 이유

`location-i` 위치에 새로 저장되는 값은 `v[location].second + 1`이므로, 기존 값과 비교할 때도 실제로 저장될 값인 `+1`까지 포함해야 한다.

기존 코드에서는 같은 최소 횟수가 이미 저장되어 있어도 재귀를 다시 호출할 수 있었다.

이번 문제는 이외의 정리할 부분이 없어 간략히 정리한다.

수정 후에는 기존 값이 새로 저장할 값보다 작거나 같다면 `continue`하여 불필요한 중복 탐색을 줄인다.
