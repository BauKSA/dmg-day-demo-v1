@echo off
setlocal enabledelayedexpansion

:: 1. Definir rutas
set GBDK_LCC="C:\Program Files\GBDK\bin\lcc.exe"
set PROJECT_DIR=%~dp0
set BUILD_DIR=%PROJECT_DIR%build
set OBJ_DIR=%BUILD_DIR%\obj
set LOG_FILE=%BUILD_DIR%\logs.txt
set ROM_OUT=%BUILD_DIR%\game.gb

:: 2. Limpieza y preparación (esto no se loguea para que el log empiece limpio)
if exist "%BUILD_DIR%" rmdir /s /q "%BUILD_DIR%"
mkdir "%OBJ_DIR%"

:: Abrimos un paréntesis para capturar TODO lo que pase adentro
(
    echo === Iniciando compilación: %date% %time% ===
    
    echo [1/3] Compilando cada archivo .c...
    for /R %%f in (*.c) do (
        echo Compilando: %%~nxf
        %GBDK_LCC% -debug -c -o "build\obj\%%~nf.o" "%%f"
    )

    echo [2/3] Entrando a la carpeta de objetos...
    pushd "%OBJ_DIR%"

    set REL_OBJS=
    for %%g in (*.o) do (
        set REL_OBJS=!REL_OBJS! %%g
    )

    echo [3/3] Linkeando ROM...
    %GBDK_LCC% -debug -Wl-yt1 -Wl-yo8 -o "%ROM_OUT%" !REL_OBJS!

    popd
    
    if exist "%ROM_OUT%" (
        echo === EXITO: ROM GENERADA ===
    ) else (
        echo === FALLO: El linker no pudo crear la ROM ===
    )

) > "%LOG_FILE%" 2>&1

:: Opcional: Avisar en consola que terminó, ya que la pantalla se quedará en blanco
echo Proceso finalizado. Revisa build\logs.txt para ver los detalles.
if not exist "%ROM_OUT%" pause