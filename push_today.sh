#!/bin/bash

# 1. 오늘 날짜 구하기 (예: 2026-05-17)
TODAY=$(date "+%Y-%m-%d")

echo "🚀 Starting daily Git backup for $TODAY..."

# 2. 깃 명령어 연속 실행
git add .
git commit -m "Daily study backup: $TODAY"
git push origin master

echo "🌿 Green grass fully planted for today!"
