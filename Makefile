GOCMD = go 
RUNCMD = run 
BUILDCMD = build 
SRCFILE = main.go
SRCDIR = cmd
TARGETFILE = StudyPlatform
TARGETDIR = bin
TARGETFILE2 = 学习平台

all: run 
run: 
	$(GOCMD) $(RUNCMD) $(SRCDIR)/$(SRCFILE)
build: 
	mkdir -p $(TARGETDIR)
	$(GOCMD) $(BUILDCMD) -o $(TARGETDIR)/$(TARGETFILE) $(SRCDIR)/$(SRCFILE)
	mv $(TARGETDIR)/$(TARGETFILE) $(TARGETDIR)/$(TARGETFILE2)
grun: 
	$(TARGETDIR)/$(TARGETFILE2)
rel: build 
crun: 
	$(TARGETDIR)/cpp/学习平台

