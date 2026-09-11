## 코드 수정 사항

### 1. `flag`를 제거하고 `dp`의 기본값을 1로 설정

#### 수정 전

```cpp
bool flag = false;

for (int i = 0; i < 4; i++)
{
    ...
    if (v[nr][nc] > v[row][col])
    {
        flag = true;
        break;
    }
}

if (!flag)
{
    dp[row][col] = 1;
    return;
}
```

#### 수정 후

```cpp
dp[row][col] = 1;
```

#### 수정 이유

`dp[row][col]`은 현재 칸에서 시작할 때 방문할 수 있는 최대 칸 수이므로, 이동할 곳이 없어도 자기 자신을 포함해 최소값은 1이다.

따라서 처음부터 `dp[row][col] = 1`로 두면 이동 가능한 칸이 있는지 별도로 확인하는 `flag`가 필요하지 않다.

---

### 2. 세 번의 4방향 탐색을 한 번으로 통합

#### 수정 전

기존에는 주변 칸을 세 번 탐색했다.

```cpp
// 1. 이동 가능한 칸 존재 여부 확인
for (...) { ... }

// 2. 필요한 dp 재귀 계산
for (...)
{
    if (v[nr][nc] > v[row][col] && dp[nr][nc] == -1)
    {
        finding(v, dp, nr, nc);
    }
}

// 3. 이동 가능한 칸 중 최대 dp 탐색
for (...)
{
    if (v[nr][nc] > v[row][col])
    {
        dp[row][col] = max(dp[row][col], dp[nr][nc]);
    }
}

dp[row][col]++;
```

#### 수정 후

```cpp
for (int i = 0; i < 4; i++)
{
    nr = row + dr[i];
    nc = col + dc[i];

    if (nr < 0 || nr >= n || nc < 0 || nc >= n)
    {
        continue;
    }

    if (v[nr][nc] > v[row][col])
    {
        if (dp[nr][nc] == -1)
        {
            finding(v, dp, nr, nc);
        }

        dp[row][col] = max(dp[row][col], dp[nr][nc] + 1);
    }
}
```

#### 수정 이유

이동 가능한 이웃을 찾은 순간 필요한 `dp`를 계산한 뒤 바로 현재 칸의 `dp`를 갱신할 수 있다.

따라서 같은 주변 4칸을 여러 번 확인할 필요가 없으며,

```cpp
dp[row][col] = max(dp[row][col], dp[nr][nc] + 1);
```

형태로 점화식도 코드에 직접 드러난다.

---

## 정리

기존:

```text
이동 가능한 칸 존재 여부 확인
→ 이동 가능한 칸의 dp 재귀 계산
→ 다시 주변을 탐색해 최대 dp 계산
→ 현재 칸 +1
```

수정 후:

```text
dp를 1로 초기화
→ 이동 가능한 이웃 탐색
→ 필요하면 재귀 계산
→ 즉시 현재 dp 갱신
```

4방향 탐색을 세 번에서 한 번으로 줄이고 `flag`와 별도의 종료 처리를 제거하면서 코드 구조가 단순해졌다.

전체 시간복잡도는 메모이제이션을 사용하므로 기존과 동일하게 `O(N²)`이지만, 중복된 주변 탐색이 줄어 상수 시간과 가독성이 개선되었다.
