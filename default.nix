with import <nixpkgs> {};

multiStdenv.mkDerivation rec {
  name = "ssa-to-srt-env";
  env = buildEnv { name = name; paths = buildInputs; };
  buildInputs = [
    gcc
    glibc
  ];

  shellHook = ''
    alias gst="git status"
    alias vim="nvim"
  '';
}
