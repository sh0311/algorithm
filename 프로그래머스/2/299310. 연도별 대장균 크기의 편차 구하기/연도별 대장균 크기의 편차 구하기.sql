-- 코드를 작성해주세요
SELECT YEAR(EA.DIFFERENTIATION_DATE) AS YEAR, B.SIZE_MAX-EA.SIZE_OF_COLONY AS YEAR_DEV, EA.ID
FROM ECOLI_DATA EA
JOIN(SELECT YEAR(EA.DIFFERENTIATION_DATE) AS YEAR, MAX(EA.SIZE_OF_COLONY) AS SIZE_MAX
    FROM ECOLI_DATA EA
    GROUP BY YEAR(EA.DIFFERENTIATION_DATE))B
ON YEAR(EA.DIFFERENTIATION_DATE)=B.YEAR
ORDER BY YEAR ASC, YEAR_DEV ASC;