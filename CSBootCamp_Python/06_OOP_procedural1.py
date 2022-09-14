import openpyxl
import math
# 학년 전체 학생의 평균 : 50점

raw_data = {}
wb = openpyxl.load_workbook('class_2_3.xlsx')
ws = wb.active
g = ws.rows

for name, score in g:
    raw_data[name.value] = score.value 

scores = list(raw_data.values())

s = 0

for score in scores:
    s += score
    
avrg = round(s/len(scores), 1)

s= 0 

for score in scores:
    s += (score - avrg) ** 2
    
variance = round(s/len(scores), 1)

std_dev = round(math.sqrt(variance), 1)

print(
    "평균: {0}, 분산: {1}, 표준편차: {2}".format(
        avrg, variance, std_dev))

if avrg < 50 and std_dev > 20:
    print("성적 저조, 편차 너무 큼")
elif avrg > 50 and std_dev > 20:
    print("성적 평균이상, 편차 큼")
elif avrg < 50 and std_dev < 20:
    print("성적 저조, 편차 적음")
elif avrg > 50 and std_dev < 20:
    print("성적 평균이상, 편차 적음")
