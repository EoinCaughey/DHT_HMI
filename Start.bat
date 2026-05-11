@echo off

cd /d %~dp0

echo Starting Flask server...
start "" py app.py

timeout /t 2 >nul

echo Opening browser...
start "" "http://127.0.0.1:5000/"

exit