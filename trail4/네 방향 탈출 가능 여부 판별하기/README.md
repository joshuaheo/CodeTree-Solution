# [[개념]네 방향 탈출 가능 여부 판별하기](https://www.codetree.ai/trails/complete/curated-cards/intro-determine-escapableness-with-4-ways)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / BFS 탐색](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

## 알아둘 점

### 1. `vector` 생성 시점 수정

#### 수정 전

```cpp
int n, m;
vector<vector<int>> v(n, vector<int>(m));
```

#### 수정 후

```cpp
int n, m;

scanf("%d %d", &n, &m);
vector<vector<int>> v(n, vector<int>(m));
```

### 수정 이유

`vector<vector<int>> v(n, vector<int>(m));`은 벡터가 생성되는 순간의 `n`, `m` 값을 사용해 크기를 결정한다.

전역 변수 `n`, `m`은 입력받기 전에는 `0`으로 초기화되므로 기존 코드는 사실상 다음과 같이 생성된다.

```cpp
vector<vector<int>> v(0, vector<int>(0));
```

이후 `scanf()`로 `n`, `m`의 값이 변경되어도 이미 생성된 `v`의 크기는 자동으로 변경되지 않는다.

따라서 입력을 먼저 받은 뒤 벡터를 생성해야 한다.

전역으로 벡터를 선언해야 한다면 빈 벡터로 선언한 뒤 `resize()`를 사용할 수도 있다.

```cpp
vector<vector<int>> v;

v.resize(n, vector<int>(m));
```
