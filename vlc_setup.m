function vlc_setup

    if ispc
        % add DLL dir to PATH
        setenv('PATH', [getenv('PATH')          ...
                        pathsep                 ...
                        fileparts(which('vlc')) ...
                        filesep                 ...
                        'win'                   ]);
    end

end

