# 코드 수정 사항

## 1. `selection` 매개변수 제거

### 수정 전

```cpp
void finding(vector<int> &moving, vector<int> &player,
             int index, int counting, int selection)
```

```cpp
if (selection != -1)
{
    if (player[selection] + moving[index] >= m)
    {
        counting++;
        player[selection] = m;
    }
    else
    {
        player[selection] += moving[index];
    }
}
```

### 수정 후

```cpp
void finding(vector<int> &moving, vector<int> &player,
             int index, int counting)
```

말을 선택하는 `for`문 안에서 바로 이동을 처리한 뒤 재귀를 호출하도록 변경했다.

```cpp
for (int i = 0; i < k; i++)
{
    if (player[i] < m)
    {
        // i번 말 이동
        finding(moving, player, index + 1, ...);
    }
}
```

### 수정 이유

기존 코드는 **현재 함수에서 말을 선택하고 다음 재귀 함수에서 그 말을 이동시키는 구조**라서 처리 시점이 한 단계씩 밀려 있었다.

이를 **말 선택 → 이동 → 다음 재귀 → 원상복구** 순서로 한 함수 안에서 처리하도록 바꿔 재귀 흐름을 단순하게 만들었다.

---

## 2. `index`를 현재 처리할 이동 번호로 변경

### 수정 전

```cpp
finding(moving, player, -1, 0, -1);
```

`selection` 구조 때문에 `index = -1`에서 시작해야 했다.

### 수정 후

```cpp
finding(moving, player, 0, 0);
```

종료 조건도 현재 처리할 이동 번호를 기준으로 판단한다.

```cpp
if (index == n)
{
    answer = max(counting, answer);
    return;
}
```

### 수정 이유

`index`가 항상 **현재 사용할 `moving[index]`의 위치**를 의미하도록 통일했다.

특수한 시작값인 `-1`을 제거하면서 인덱스가 한 칸씩 어긋나는 구조를 없애고, 배열 범위 관련 실수를 줄였다.

---

## 3. `counting`을 직접 수정하지 않고 다음 재귀에 전달

### 수정 전

```cpp
if (player[selection] + moving[index] >= m)
{
    counting++;
}
```

현재 함수의 `counting` 값을 직접 변경했다.

### 수정 후

```cpp
bool arrival = false;

if (player[i] + moving[index] >= m)
{
    arrival = true;
    player[i] = m;
}

finding(moving, player, index + 1, counting + arrival);
```

### 수정 이유

`counting`은 값으로 전달되는 변수이므로 현재 값을 직접 수정할 필요가 없다.

현재 함수의 `counting`은 유지하고, 다음 재귀 호출에만 `counting + arrival`을 넘기면 별도의 원상복구가 필요하지 않아 상태 관리가 단순해진다.

---

## 정리

기존 코드와 비교했을 때 핵심 변화는 **성능 최적화보다는 백트래킹 구조의 단순화**에 있다.

기존:

```text
말 선택
→ 다음 재귀 호출
→ 선택했던 말 이동
→ 다시 말 선택
```

수정 후:

```text
말 선택
→ 즉시 이동
→ 다음 재귀 호출
→ 이동 상태 원상복구
```

이렇게 변경하면서 `selection`과 `index = -1` 같은 특수 처리가 사라지고, 각 재귀 단계가 **현재 이동 한 번을 처리한다**는 명확한 의미를 가지게 되었다.
