#!/usr/bin/env python3
import os
import sys
import time
import subprocess
from datetime import datetime

# rich 라이브러리 자동 체크 및 설치
try:
    from rich.console import Console
    from rich.panel import Panel
    from rich.progress import (
        Progress, SpinnerColumn, BarColumn, TextColumn, TaskProgressColumn
    )
    from rich.table import Table
except ImportError:
    print("[*] Installing 'rich' library...")
    subprocess.run([sys.executable, "-m", "pip", "install", "rich"], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    from rich.console import Console
    from rich.panel import Panel
    from rich.progress import (
        Progress, SpinnerColumn, BarColumn, TextColumn, TaskProgressColumn
    )
    from rich.table import Table

console = Console()
LOG_FILE = "git_sync.log"

def run_cmd(cmd):
    """리눅스 명령어 실행 및 결과 반환"""
    res = subprocess.run(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return res.returncode == 0, res.stdout.strip(), res.stderr.strip()

def main():
    branch = sys.argv[1] if len(sys.argv) > 1 else "master"
    console.clear()

    # 상단 굵은 정체 타이틀 (장난스러운 요소 제거)
    console.print(Panel(f"[bold cyan]Git Auto-Sync Protocol[/bold cyan] | Target Branch: [bold yellow]{branch}[/bold yellow]", border_style="cyan", expand=False))
    console.print()

    # 1. 깃 저장소 확인
    if not os.path.exists(".git"):
        console.print("[bold red]ERROR: Not a git repository.[/bold red]")
        sys.exit(1)

    # 2. 프로그레스 작업 진행 (요청하신 점선 형태의 직관적인 문구)
    progress = Progress(
        SpinnerColumn(spinner_name="dots", style="cyan"),
        TextColumn("[white]{task.description}[/white]"),
        BarColumn(bar_width=30, complete_style="cyan", finished_style="green"),
        TaskProgressColumn(style="dim white"),
        console=console
    )

    with progress:
        # Step 1: Git Add
        t1 = progress.add_task("Git Staging Workspace.........", total=100)
        for _ in range(5):
            time.sleep(0.04)
            progress.advance(t1, 20)
        success, out, err = run_cmd("git add .")
        if not success:
            console.print(f"[bold red]✗ Git Staging Failed: {err}[/bold red]")
            sys.exit(1)
        console.print("  [bold green]✓[/bold green] Git Staging Completed")

        # Step 2: Git Commit
        t2 = progress.add_task("Git Committing Payload........", total=100)
        for _ in range(5):
            time.sleep(0.04)
            progress.advance(t2, 20)
        
        commit_msg = f"Auto-backup: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
        success, out, err = run_cmd(f'git commit -m "{commit_msg}"')
        
        if not success and ("nothing to commit" in err.lower() or "nothing to commit" in out.lower()):
            console.print("  [dim cyan]ℹ Git Commit Skipped (No changes detected)[/dim cyan]")
        elif not success:
            console.print(f"[bold red]✗ Git Commit Failed: {err}[/bold red]")
            sys.exit(1)
        else:
            console.print("  [bold green]✓[/bold green] Git Commit Created")

        # Step 3: Git Push
        t3 = progress.add_task("Git Uploading.................", total=100)
        for _ in range(10):
            time.sleep(0.05)
            progress.advance(t3, 10)
        
        success, out, err = run_cmd(f"git push origin {branch}")
        if not success:
            console.print(f"[bold red]✗ Git Upload Failed: {err}[/bold red]")
            sys.exit(1)
        console.print(f"  [bold green]✓[/bold green] Git Upload Finished to [origin/{branch}]")

    console.print()

    # 3. 결과 요약 표 (정갈한 시스템 스타일)
    table = Table(title="Execution Summary", border_style="dim white", header_style="bold cyan")
    table.add_column("Task Name", style="white", justify="left")
    table.add_column("Status", style="bold green", justify="left")
    
    table.add_row("Target Branch", branch)
    table.add_row("Sync Status", "SUCCESS")
    table.add_row("Timestamp", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

    console.print(table)
    console.print()

if __name__ == "__main__":
    main()
