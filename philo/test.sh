#!/bin/sh
# 명령어를 1000번 반복 실행
OK_count=0
KO_count=0
for i in $(seq 1 1000); do
  # 명령어를 실행하고 마지막 줄을 저장
  last_output=$(./philo 199 0 0 0 | tail -n 1)
  # "died" 문자열이 포함되어 있는지 확인
  if echo "$last_output" | grep -q "died"; then
    OK_count=$((OK_count + 1))
  else
    KO_count=$((KO_count + 1))
  fi
done
# 결과 출력
echo "OK count: $OK_count"
echo "KO count: $KO_count"