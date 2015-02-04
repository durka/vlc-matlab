function varargout = vlc_wrapper(task, varargin)

    if strcmp(computer, 'MACI64')
        switch task
            case {'init', 'open'}
                varargout{1} = 0;
            case 'frame'
                varargout{1} = 1000;
            case 'info'
                varargout{1} = [25 20*60*1000];
        end
    else
        tasks = {'init'   , ...
                 'release', ...
                 'open'   , ...
                 'close'  , ...
                 'frame'  , ...
                 'play'   , ...
                 'pause'  , ...
                 'info'   , ...
                 'cleanup'};

        i = find(strcmpi(task, tasks))-1;
        fprintf('Executing VLC operation #%d\n', i);
        [varargout{1:nargout}] = vlc(i, varargin{:});
    end

end
