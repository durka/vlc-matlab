function varargout = vlc_wrapper(task, varargin)

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
