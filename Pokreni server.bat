@echo off
cd /d "%~dp0"
title Balkan Revolution RP - Server
echo Pokrecem Balkan Revolution RP server...
echo Ako je port 7777 zauzet, prvo zatvori stari server.
echo.
samp-server.exe
echo.
echo Server je zaustavljen. Provjeri server_log.txt ako je doslo do greske.
pause
