::init context
@ECHO OFF

::init vars
SET INPUT_DATE=%DATE:~-8,2%%DATE:~-5,2%%DATE:~-2,2%
SET SRC_DIR=1?????*
SET DST_DIR=_latest\


SET /P INPUT_DATE="�w����ȍ~���u%DST_DIR%�v�t�H���_�ɃR�s�[���܂��B(��:120627):"

::ECHO %INPUT_DATE%

::main routine

FOR /D %%A IN (%SRC_DIR%) DO CALL :SUB1 %%A

GOTO END



::sub routines
:SUB1
	SET DIRNAME=%1
	IF "%DIRNAME:~0,6%" GTR "%INPUT_DATE%" (
		XCOPY /S /E /F /G /R /K /Y %1\* %DST_DIR%
	)
EXIT /B


:END
	SET /P END="�R�s�[���I�����܂����BEnter�L�[�ŏI�����܂��B"
EXIT /B