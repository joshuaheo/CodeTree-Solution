# [[테스트]알파벳과 사칙연산](https://www.codetree.ai/trails/complete/curated-cards/test-calculations-with-alphabet)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / Backtracking / K개 중 하나를 N번 선택하기(Simple)](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 90 XP |

## 개선점 및 배운 점

* 알파벳 문자는 연속된 숫자 코드값을 가지므로, 다음과 같이 알파벳을 배열 인덱스로 변환할 수 있다.

```cpp
v[alphabet - 'a']
```

예를 들어 `'c' - 'a'`의 결과는 `2`이므로 `v[2]`에 접근한다. 알파벳별 빈도 계산이나 값을 저장할 때 자주 활용할 수 있다.

* 계산 결과가 모두 음수일 수 있으므로 최댓값을 `0`으로 초기화하면 잘못된 결과가 나올 수 있다. 첫 번째 계산 결과를 최댓값으로 사용하거나 `INT_MIN`으로 초기화해야 한다.

* 재귀 함수에서 문자열을 수정하지 않는다면 값으로 전달하기보다 `const string&`로 전달해 불필요한 복사를 막는 것이 좋다.

```cpp
void finding(const string& str, ...)
```

* 반환형이 `int`인 함수는 입력 조건상 실행되지 않을 경로라도 마지막에 반환값을 작성해야 한다. 그렇지 않으면 `control reaches end of non-void function` 경고가 발생할 수 있다.

* `max()`를 사용할 때는 해당 함수가 정의된 `<algorithm>` 헤더를 직접 포함하는 것이 안전하다.

* `char str[200]`에 길이 200인 문자열을 저장하려면 문자열 끝의 널 문자까지 필요하므로 배열 크기를 최소 201로 잡아야 한다. C++에서는 `string`으로 입력받는 편이 더 간단하고 안전하다.

