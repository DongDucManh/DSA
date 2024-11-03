from itertools import combinations

# Các hướng di chuyển của quân mã
dx = [-2, -2, -1, -1, 1, 1, 2, 2]
dy = [-1, 1, -2, 2, -2, 2, -1, 1]

# Hàm kiểm tra vị trí hợp lệ trên bàn cờ
def is_valid(x, y, n):
    return 0 <= x < n and 0 <= y < n

# Hàm kiểm tra nếu hai quân mã tấn công nhau
def attacks(x1, y1, x2, y2):
    for i in range(8):
        if x1 + dx[i] == x2 and y1 + dy[i] == y2:
            return True
    return False

# Hàm tính số cách đặt 3 quân mã không tấn công nhau
def count_knights_triplets(n):
    total_valid_triplets = 0
    positions = [(i, j) for i in range(n) for j in range(n)]
    
    # Duyệt qua tất cả các tổ hợp của 3 vị trí trên bàn cờ
    for (x1, y1), (x2, y2), (x3, y3) in combinations(positions, 3):
        # Kiểm tra xem ba quân mã này có tấn công lẫn nhau không
        if not (attacks(x1, y1, x2, y2) or attacks(x1, y1, x3, y3) or attacks(x2, y2, x3, y3)):
            total_valid_triplets += 1
    
    return total_valid_triplets

# Đọc giá trị n và in kết quả
n = int(input())
print(count_knights_triplets(n))
