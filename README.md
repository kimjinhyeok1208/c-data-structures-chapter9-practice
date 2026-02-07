# 📘 Chapter 09 – Sorting Experiments README

> 교재: 한빛아카데미 『C로 배우는 쉬운 자료구조 4판』
> 주제: 정렬 알고리즘 비교 · 실험 · 분석

본 README는 Chapter 09에서 구현한 **3가지 실험 중심 문제**에 대한 정리 문서이다.
단순 정렬 구현이 아닌, **성능 비교 / 피벗 전략 분석 / 안정성 검증**에 초점을 맞추었다.

---

# 📂 디렉터리 구조

```
chapter09/
 ├─ sort_performance_compare.c
 ├─ quick_pivot_compare.c
 ├─ stable_vs_unstable.c
 └─ README.md
```

---

# ✅ 문제 1. 정렬 알고리즘 성능 비교

## 📌 파일

`sort_performance_compare.c`

## 📌 목적

Selection Sort, Quick Sort, Merge Sort의 **비교 횟수 및 교환 횟수**를 측정하여 성능 차이를 수치로 확인한다.

## 📌 구현 내용

* 동일한 원본 배열을 복사하여 각 정렬에 적용
* 전역 변수로 비교 횟수 / 교환 횟수 카운트
* 정렬 완료 후 결과 출력

## 📌 실험 결과 해석

* Selection Sort → 비교 횟수 많음 (O(n²))
* Quick / Merge → 비교 횟수 감소 (O(n log n))
* Merge는 교환 개념이 아닌 병합 중심

## 📌 학습 포인트

* 시간 복잡도의 체감
* 이론과 실제 실행 결과 비교
* 알고리즘 효율성 분석 방법 학습

---

# ✅ 문제 2. 퀵 정렬 피벗 전략 비교

## 📌 파일

`quick_pivot_compare.c`

## 📌 목적

퀵 정렬에서 **피벗 선택 전략**에 따른 성능 차이를 비교한다.

## 📌 비교 전략

1. 첫 번째 원소를 피벗으로 선택
2. 중간 원소를 피벗으로 선택

## 📌 실험 방법

* 이미 정렬된 배열 입력
* 비교 횟수 출력

## 📌 실험 결과 해석

* 첫 원소 피벗 → 최악의 경우 O(n²) 발생
* 중간 피벗 → 비교 횟수 감소

## 📌 학습 포인트

* 피벗 선택의 중요성
* 퀵 정렬 최악 상황 이해
* 분할 정복 알고리즘의 민감성

---

# ✅ 문제 3. 안정 정렬 vs 불안정 정렬 비교

## 📌 파일

`stable_vs_unstable.c`

## 📌 목적

구조체 데이터를 정렬하여 **안정 정렬과 불안정 정렬의 차이**를 확인한다.

## 📌 정렬 방식

* Merge Sort → 안정 정렬
* Heap Sort → 불안정 정렬

## 📌 실험 데이터

```c
typedef struct {
    int score;
    char name[20];
} Student;
```

같은 점수를 가진 학생들의 순서가 유지되는지 비교한다.

## 📌 실험 결과 해석

* Merge Sort → 기존 순서 유지
* Heap Sort → 순서 변경 가능

## 📌 학습 포인트

* Stable Sort 개념 이해
* 실제 데이터 정렬에서 안정성의 중요성 확인

