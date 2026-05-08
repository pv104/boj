-- 코드를 작성해주세요

# 분기 정보
# year 상관없이,
# 0101-0331 1분기, 0401-0630 2분기, 0701-0930 3분기, 1001-1231 4분기
# 출력: 해당 분기의 대장균 행 수

# 1Q 그룹에 2개, 2Q 그룹에 2개... 
# 자바 코드라면
# for (int i=0; i<size; i++) {
# if(differentation_date.y >= 1 && y <= 3) 1q++;
# }
# sql로 어떻게 옮김??
# count 함수: 조건에 맞는 행의 개수
# 조건: y >= 1 && y <= 3 then, when y >= 4 && y <= 6.
# case when 조건 then 변수가 없는데
# subquery를 만든다면: 테이블에서 조건에 맞는 아무 행이나 뽑으면 되긴 해


SELECT CONCAT(QUARTER(DIFFERENTIATION_DATE), 'Q') AS QUARTER, COUNT(*) AS ECOLI_COUNT
FROM ECOLI_DATA
GROUP BY QUARTER(DIFFERENTIATION_DATE)
ORDER BY QUARTER(DIFFERENTIATION_DATE)

