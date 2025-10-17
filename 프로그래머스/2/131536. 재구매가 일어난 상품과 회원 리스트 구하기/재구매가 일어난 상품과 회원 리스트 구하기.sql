-- 코드를 입력하세요

-- 회원 아이디와 상품 아이디가 같은 컬럼의 수를 찾고, 거기서 uid랑 pid
-- 정렬조건은 uid asc, pid desc

-- ONLINE_SALE에서 USER_ID로 묶었을때, COUNT(*) > 1인 USER_ID를 가지고
-- PRODUCT_ID


SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) > 1
ORDER BY USER_ID, PRODUCT_ID DESC;