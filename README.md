# Bubbles
Play for fun

Move LocalDerivedDataCache into GameDir folder:

Open BaseEngine.ini > UnrealEngineVersion\Engine\Config\BaseEngine.ini
Find: [InstalledDerivedDataBackendGraph]
Change: Path="%ENGINEVERSIONAGNOSTICUSERDIR%DerivedDataCache"
to: Path="%GAMEDIR%LocalDerivedDataCache"
All cache will be saved in to directory of your project
