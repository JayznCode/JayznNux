#!/usr/bin/env python3
import os
import sys
import time
import random
import subprocess
from datetime import datetime

# 터미널 외부 라이브러리 자동 체크 및 설치
try:
    from rich.console import Console
    from rich.panel import Panel
    from rich.layout import Layout
    from rich.live import Live
    from rich.progress import (
        Progress, SpinnerColumn, BarColumn, TextColumn, TaskProgressColumn
    )
    from rich.text import Text
    from rich.syntax import Syntax
    from rich.table import Table
    from rich.style import Style
except ImportError:
    print("[*] Initializing Matrix Neural Protocol (Installing 'rich' UI framework)...")
    subprocess.run([sys.executable, "-m", "pip", "install", "rich"], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    from rich.console import Console
    from rich.panel import Panel
    from rich.layout import Layout
    from rich.live import Live
    from rich.progress import (
        Progress, SpinnerColumn, BarColumn, TextColumn, TaskProgressColumn
    )
    from rich.text import Text
    from rich.syntax import Syntax
    from rich.table import Table
    from rich.style import Style

console = Console()
LOG_FILE = "git_sync.log"
console = Console()
LOG_FILE = "git_sync.log"

HACKER_ART = """
[bold green]
  ██████╗ ██╗████████╗    ██╗  ██╗██████╗  ██████╗██╗  ██╗███╗   ██╗██╗   ██╗██╗  ██╗
 ██╔════╝ ██║╚══██╔══╝    ██║  ██║██╔══██╗██╔════╝██║  ██║████╗  ██║██║   ██║╚██╗██╔╝
 ██║  ███╗██║   ██║       ███████║██████╔╝██║     ███████║██╔██╗ ██║██║   ██║ ╚███╔╝ 
 ██║   ██║██║   ██║       ██╔══██║██╔══██╗██║     ██╔══██║██║╚██╗██║██║   ██║ ██╔██╗ 
 ╚██████╔╝██║   ██║       ██║  ██║██║  ██║╚██████╗██║  ██║██║ ╚████║╚██████╔╝██╔╝ ██╗
  ╚═════╝ ╚═╝   ╚═╝       ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
[/bold green]
"""

HEX_STREAM = [
    "0x7F 0x45 0x4C 0x46 0x02 0x01 0x01 0x00 0x00 0x00 0x00 0x00 SYSCALL_READY",
    "MEM_ALLOC 0x00401000 - 0x00402000 [r-xp] /usr/bin/git_engine",
    "CONNECT remote://github.com:JayznCode/JayznNux.git VIA SSH_RSA2048",
    "CIPHER_SUITE: AES_256_GCM_SHA384 | PROTOCOL: TLSv1.3_ENCRYPTION",
    "BYPASSING PROXY NODES... [127.0.0.1:9050 -> TOR_NETWORK -> GITHUB_EDGE]",
    "ANALYZING GIT METADATA... CHECKSUM SHA256 VALIDATED",
    "CREATING VIRTUAL PIPELINE... THREADS: 16 | PRIORITY: REALTIME",
]

def run_cmd(cmd):
    """Executes OS commands silently and captures output"""
    res = subprocess.run(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return res.returncode == 0, res.stdout.strip(), res.stderr.strip()

def matrix_glitch_effect(duration=1.2):
    """Prints fast cyberpunk matrix stream text"""
    end_time = time.time() + duration
    chars = "01010101ABCDEF#$%-=@!&*"
    while time.time() < end_time:
        line = "".join(random.choice(chars) for _ in range(70))
        console.print(f"[bold green]{line}[/bold green]")
        time.sleep(0.04)

def main():
    branch = sys.argv[1] if len(sys.argv) > 1 else "master"
    console.clear()

    # 1. Title Banner
    console.print(HACKER_ART)
    console.print(Panel("[bold green]CYBERPUNK GIT AUTO-INJECTOR v4.04 :: SYSTEM OVERRIDE ACTIVE[/bold green]", border_style="green", expand=False))
    console.print()

    # Matrix terminal glitch simulation
    with console.status("[bold green]Bypassing security protocols & connecting to GitHub Edge...[/bold green]", spinner="dots"):
        time.sleep(1.0)

    # 2. Check Repository Status
    if not os.path.exists(".git"):
        console.print("[bold red]❌ FATAL ERROR: TARGET IS NOT A GIT REPOSITORY! ABORTING SYSCALL.[/bold red]")
        sys.exit(1)

    # 3. Hex Stream Log Simulation
    console.print("[bold green]=== RUNNING SYSTEM DIAGNOSTICS & TELEMETRY ===[/bold green]")
    for log in HEX_STREAM:
        console.print(f"[dim green][{datetime.now().strftime('%H:%M:%S.%f')[:-3]}][/dim green] [green]{log}[/green]")
        time.sleep(0.08)
    console.print()

    # 4. Interactive Hacker Progress Panel
    progress = Progress(
        SpinnerColumn(spinner_name="dots12", style="bold green"),
        TextColumn("[bold green]{task.description}[/bold green]"),
        BarColumn(bar_width=35, complete_style="bold green", finished_style="bold bright_green"),
        TaskProgressColumn(style="bold green"),
        console=console
    )

    with progress:
        # Step 1: Git Add
        t1 = progress.add_task("[CYBER_ADD] Staging Workspace Objects...", total=100)
        for _ in range(5):
            time.sleep(0.04)
            progress.advance(t1, 20)
        success, out, err = run_cmd("git add .")
        if not success:
            console.print(f"[bold red]❌ STAGING FAILURE: {err}[/bold red]")
            sys.exit(1)
        console.print("[bold green]  ✔ [STAGING_COMPLETE] All files payload injected to index.[/bold green]")

        # Step 2: Git Commit
        t2 = progress.add_task("[CYBER_COMMIT] Generating Quantum SHA-Hash...", total=100)
        for _ in range(5):
            time.sleep(0.04)
            progress.advance(t2, 20)
        
        commit_msg = f"Auto-backup: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')} [CYBER_NODES_INJECTED]"
        success, out, err = run_cmd(f'git commit -m "{commit_msg}"')
        
        if not success and "nothing to commit" in err.lower() or "nothing to commit" in out.lower():
            console.print("[bold cyan]  ℹ [COMMIT_SKIPPED] Zero delta detected. Working tree clean.[/bold cyan]")
        elif not success:
            console.print(f"[bold red]❌ COMMIT FAILURE: {err}[/bold red]")
            sys.exit(1)
        else:
            console.print("[bold green]  ✔ [COMMIT_SUCCESS] Block added to local timeline.[/bold green]")

        # Step 3: Git Push
        t3 = progress.add_task(f"[CYBER_PUSH] Transmitting Packet Stream to [origin/{branch}]...", total=100)
        for _ in range(10):
            time.sleep(0.06)
            progress.advance(t3, 10)
        
        success, out, err = run_cmd(f"git push origin {branch}")
        if not success:
            console.print(f"[bold red]❌ TRANSMISSION ERROR: {err}[/bold red]")
            sys.exit(1)
        console.print(f"[bold green]  ✔ [PUSH_SUCCESS] Stream merged into remote branch [origin/{branch}].[/bold green]")

    console.print()
    # 5. Final Mission Accomplished Terminal Table
    summary_table = Table(title="[bold green]=== SYSTEM INJECTION TELEMETRY SUMMARY ===[/bold green]", border_style="green", header_style="bold bright_green")
    summary_table.add_column("Parameter", style="cyan", justify="left")
    summary_table.add_column("Status / Value", style="bold green", justify="left")
    
    summary_table.add_row("Target Remote", "git@github.com:JayznCode/JayznNux.git")
    summary_table.add_row("Target Branch", branch)
    summary_table.add_row("Encryption Status", "256-Bit Quantum Safe GCM")
    summary_table.add_row("Sync Status", "SUCCESSFUL (0 PACKET LOSS)")
    summary_table.add_row("Timestamp", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

    console.print(summary_table)
    console.print()
    console.print(Panel("[bold green]✔ ACCESS GRANTED :: GITHUB REPOSITORY SYNCED SUCCESSFULLY[/bold green]", border_style="bright_green"))

if __name__ == "__main__":
    main()
