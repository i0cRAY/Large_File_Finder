import os

def find_large_files(folder_path, top_n):
    if not os.path.exists(folder_path):
        print("cannot find folder")
        return

    print(f"Scanning for large files in [{folder_path}]\n")
    file_list = []

    # 深入走訪所有子資料夾
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            file_path = os.path.join(root, file)
            try:
                size_mb = os.path.getsize(file_path) / (1024 * 1024)
                file_list.append((file_path, size_mb))
            except Exception:
                pass

    file_list.sort(key = lambda x: x[1], reverse = True)

    print(f"Top {top_n} largest files:")
    print("-" * 50)
    for i, (path, size) in enumerate(file_list[:top_n], 1):
        print(f"Top {i} | {size:.2f} MB")
        print(f"Path: {path}\n")


if __name__ == "__main__":
    target_dir = input("Please enter the folder path to scan (e.g., C:\\Users or Downloads folder path): ")
    n = int(input("How many of the largest files do you want to find? "))

    find_large_files(target_dir, n)
