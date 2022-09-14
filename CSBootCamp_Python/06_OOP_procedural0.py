from openpyxl import *
wb = load_workbook('exam.xlsx')
print(wb.sheetnames)

# 활성화된 sheet 받아오기
ws = wb.active
print(ws)

# 엑셀파일의 셀들 읽어들이기
g = ws.rows
cells = next(g) # 첫번째 행 가져오기
print(cells)

# 1행 확인
keys = []
for cell in cells:
    keys.append(cell.value)
print(keys)

# student data 확인
student_data = []
for row in g:
    dic = {k : c.value for k, c in zip(keys, row)}
    student_data.append(dic)
print(student_data)