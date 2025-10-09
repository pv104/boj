-- 코드를 작성해주세요
select COUNT(*) as COUNT
from ECOLI_DATA
where (GENOTYPE & 2 != 2) AND
        ((GENOTYPE & 1 > 0) OR
        (GENOTYPE & 4 > 0));