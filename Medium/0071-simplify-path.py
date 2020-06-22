class Solution:
    def simplifyPath(self, path: str) -> str:
        path_list = []
        for name in path.split('/'):
            if name == '..':
                if path_list:
                    path_list.pop()
            elif name != '.' and name != '':
                path_list.append(name)
        return '/' + '/'.join(path_list)
