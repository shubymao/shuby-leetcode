import os
import json
from datetime import datetime
from shutil import copyfile

TEMPLATE_CODE_PATH = os.path.join("template", "code.cpp")
SOLUTION_ROOT = "./solutions"
class Solution:
    def __init__(self):
        self.prompt_user_input()
        self.author = "Shuby Mao"
        self.date = datetime.now().isoformat()
    
    def prompt_user_input(self):
        self.name = input("Problem name (e.g two-sum): \n")
        assert self.name != "", "Please enter a valid problem name"
        self.time_complexity = input("Time Complexity (e.g n, nlogn, n^2 ...):\n") or ""
        self.space_complexity = input("Space Complexity (e.g n, nlogn, n^2 ...):\n") or ""
        self.notes = input("Notes: (hit enter if no notes) \n") or ""

    def get_full_name(self):
        return self.name.replace("-", " ").title()

    def to_json(self) -> dict:
        return {
            "name": self.get_full_name(),
            "link": "https://leetcode.com/problems/" + self.name,
            "author": self.author,
            "date": self.date,
            "time_complexity": f'O({self.time_complexity})',
            "space_complexity": f'O({self.space_complexity})',
            "notes": self.notes
        }


def add_solution(solution: Solution):
    """
    Adds a solution to the solutions directory.
    """
    solution_folder = os.path.join(SOLUTION_ROOT, solution.name)
    if not os.path.exists(solution_folder):
        print("Creating directory: " + solution_folder)
        os.mkdir(solution_folder)
    solution_file = os.path.join(solution_folder, "code.cpp")
    if not os.path.exists(solution_file):
        print("Creating file: " + solution_file)
        copyfile(TEMPLATE_CODE_PATH, solution_file)
    metadata_file = os.path.join(solution_folder, "metadata.json")
    with open(metadata_file, "w") as f:
        print("Writing metadata to: " + metadata_file)
        json.dump(solution.to_json(), f, ensure_ascii=False, indent=4)
    print("Solution added.")
    
if __name__ == "__main__":
    solution = Solution()
    add_solution(solution)