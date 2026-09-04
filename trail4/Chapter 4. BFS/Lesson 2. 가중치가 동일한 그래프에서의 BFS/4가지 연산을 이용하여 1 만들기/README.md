# [[챌린지]4가지 연산을 이용하여 1 만들기](https://www.codetree.ai/trails/complete/curated-cards/challenge-make-one-using-four-operations)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / 가중치가 동일한 그래프에서의 BFS](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 어려움 |
| 경험치 | 90 XP |

### 권장 개선사항: `flag` 대신 `bool` 반환값으로 조기 종료

현재는 전역 변수 `flag`를 사용해 `1`을 찾았는지 전달한다.

```cpp
bool flag = false;

if (num == 1)
{
    flag = true;
    return;
}
```

`pushing()`이 성공 여부를 `bool`로 반환하도록 바꾸면 전역 변수 없이 함수의 반환값으로 탐색 종료 신호를 전달할 수 있다.

```cpp
bool pushing(...)
{
    if (num == 1)
    {
        return true;
    }

    ...

    return false;
}
```

여러 `pushing()`을 호출할 때는 `||`의 short-circuit을 이용할 수도 있다.

```cpp
if (pushing(q, visit, num - 1) ||
    pushing(q, visit, num + 1))
{
    return true;
}
```

첫 번째 호출에서 `true`가 반환되면 이후 호출은 실행되지 않으므로, **정답을 찾은 순간 불필요한 탐색을 바로 중단할 수 있다.**

현재 `flag` 방식도 문제는 없지만, `bool` 반환 방식은 전역 상태를 줄이고 조기 종료 흐름을 더 명확하게 만들 수 있어 권장할 수 있다.

