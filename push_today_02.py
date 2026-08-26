#!/usr/bin/env python3
import os
import sys
import time
import subprocess
from datetime import datetime

# rich 라이브러리 검사
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
    """리눅스 명령어 실행 함수"""
    res = subprocess.run(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return res.returncode == 0, res.stdout.strip(), res.stderr.strip()

def main():
    branch = sys.argv[1] if len(sys.argv) > 1 else "master"
    console.clear()

    # 상단 대시보드 타이틀 (담백하고 직관적으로 변경)
    console.print(Panel(f"[bold white]Git Repository Sync Tool[/bold white] | [cyan]Branch: {branch}[/cyan]", border_style="blue", expand=False))
    console.print()

    # 1. Git 저장소 검사
    if not os.path.exists(".git"):
        console.print("[bold red]Error: Not a git repository.[/bold red]")
        sys.exit(1)

    # 2. 진행 상황 출력 (깔끔한 메시지)
    progress = Progress(
        SpinnerColumn(spinner_name="dots", style="cyan"),
        TextColumn("[white]{task.description}[/white]"),
        BarColumn(bar_width=30, complete_style="cyan", finished_style="green"),
        TaskProgressColumn(style="dim white"),
        console=console
    )

    with progress:
        # Step 1: Git Add
        t1 = progress.add_task("Staging changes (git add)...", total=100)
        time.sleep(0.1)
        progress.advance(t1, 50)
        success, out, err = run_cmd("git add .")
        if not success:
            console.print(f"[bold red]✗ git add failed: {err}[/bold red]")
            sys.exit(1)
        progress.advance(t1, 50)
        console.print("  [bold green]✓[/bold green] Staging completed")

        # Step 2: Git Commit
        t2 = progress.add_task("Creating commit...", total=100)
        time.sleep(0.1)
        progress.advance(t2, 50)
        
        commit_msg = f"Auto-backup: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
        success, out, err = run_cmd(f'git commit -m "{commit_msg}"')
        progress.advance(t2, 50)
        
        if not success and ("nothing to commit" in err.lower() or "nothing to commit" in out.lower()):
            console.print("  [dim cyan]ℹ Working tree clean (No changes to commit)[/dim cyan]")
        elif not success:
            console.print(f"[bold red]✗ git commit failed: {err}[/bold red]")
            sys.exit(1)
        else:
            console.print("  [bold green]✓[/bold green] Commit created")

        # Step 3: Git Push
        t3 = progress.add_task(f"Pushing to origin/{branch}...", total=100)
        time.sleep(0.1)
        progress.advance(t3, 50)
        
        success, out, err = run_cmd(f"git push origin {branch}")
        progress.advance(t3, 50)
        
        if not success:
            console.print(f"[bold red]✗ git push failed: {err}[/bold red]")
            sys.exit(1)
        console.print(f"  [bold green]✓[/bold green] Pushed to origin/{branch}")

    console.print()

    # 3. 결과 리포트 요약 표
    table = Table(title="[bold]Execution Summary[/bold]", border_style="dim white", header_style="bold cyan")
    table.add_column("Task", style="white", justify="left")
    table.add_column("Status", style="green", justify="left")
    
    table.add_row("Target Branch", branch)
    table.add_row("Sync Result", "SUCCESS")
    table.add_row("Timestamp", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

    console.print(table)
    console.print()

if __name__ == "__main__":
    main()
