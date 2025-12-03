# Git Practice

A refresher for anyone who has used Git before, or for people who want to learn in a safe space.

<details>
    <summary id="Workflow-overview">Workflow overview</summary>

## Workflow overview

We will step through each of these points below. But this is a rough side by side difference of working with SVN versus Git.

<table>
<tr>
<th>SVN</th>
<th>Git</th>
</tr>

<tr>
<td>checkout repo</td>
<td>clone repo</td>
</tr>

<tr>
<td>update</td>
<td>
fetch<br>
pull
</td>
</tr>

<tr>
<td>(write lots of code)</td>
<td>
checkout a feature branch<br>
&nbsp&nbsp&nbsp(write some code)<br>
local commit<br>
&nbsp&nbsp&nbsp(write some more code)<br>
local commit<br>
&nbsp&nbsp&nbsp(repeat)
</td>
</tr>

<tr>
<td>commit</td>
<td>
push<br><br>
pull request<br>
someone reviews and approves<br>
merge pull request
</td>
</tr>

</table>

</details>

---

<details>
    <summary id="Set-up-your-project">Set up your project</summary>

## Set up your project

First, you need a GitHub account. If you haven't got one, create one now. For the username use the naming convention: \<firstname\>\<surname\>AH e.g. `RichardSteeleAH`.

Next we need to do some setup on your machine. The following is for Windows environments. Linux and macOS are very similar though.

If you do not have Git installed already then go to https://git-scm.com/install/ and download the latest stable release for Windows. I can't remember the options it gives you but if given the option then make sure you include *Git bash* with your install.

For security we will be using **SSH keys**. Add one now.

To generate a key, right click anywhere, choose *Show more options*, and click *Open Git Bash Here*:

```
# Generate a key and save it to the default location with the default options

ssh-keygen -t ed25519 -C "<your GitHub email address>"

# e.g.
# ssh-keygen -t ed25519 -C "richard.steele@allen-heath.com"
```

View your public key:

```
cat ~/.ssh/id_ed25519.pub
```

Copy the entire output (ensure no white space at the end).

Next add the key to your GitHub account:

1.  Go to https://github.com/settings/keys
2.  Click **New SSH key**
3.  Paste your public key into **Key**
4.  Give it a meaningful title e.g. dLive VM
5.  Click **Add SSH key**

Test:

```
ssh -T git@github.com
```

> Note you will need to set up new key per machine. Expect to have separate keys for your Windows pc and each of your virtual machines.

Go to: https://github.com/Allen-Heath/GitPractice (If you're reading this already, open it in a new window so you can follow along.)

Click the green **Code** button, change from **HTTPS** to **SSH** then copy the clone link. SSH links will look like this:

```
git@github.com:Allen-Heath/<RepoName>.git
```

You will **not** use HTTPS for cloning internal repos. We will always use **SSH keys**.

Go to wherever you want this project to live on your PC. It doesn't matter where, mine is in: C:\Users\Richard.Steele

Right-click → **Git Bash Here**, then type `git clone` then right-click and paste the link you copied before. It should look like this:

```
git clone git@github.com:Allen-Heath/<RepoName>.git
```

Press return. This downloads the repo to your computer.

Move into the folder:

```
cd GitPractice
```

Almost done.

---

Lastly, you are currently on the **main** branch. This is **bad**. Do not work in `main`. Do not be in your `main` branch for long. `main` is your important, stable branch. Not a working branch. It should match other people's `main`. It is the single source of truth in your repository.

Note that historically this was called `master` however the convention has recently changed. You will see Git veterans mix it up still although the meaning is the same.

Check your branches:

```
git branch
```

To create and switch to a new safe working branch:

```
# `-b` creates a new branch from your current state, WorkingBranch is a name I made up, make your own up if you want

git checkout -b WorkingBranch
```

Check again with:

```
git branch
```

You should see both branches, with your working branch highlighted.

Done.

</details>

---

<details>
  <summary id="A-nicer-git-environment">A nicer git environment</summary>

## A nicer git environment

Viewing Git as a **graph** or **tree** is the best way to understand branches and merges. There are many tools (Git GUI, GitKraken, TortoiseGit, etc.) but the one I recommend is the **Git Graph** extension in VS Code. Even if you are familiar with TortoiseSVN then you are familiar with how rubbish it can be. So now is a good time to start using something better.

Install Git Graph:

1.  In VS Code, open the Extensions panel (four squares icon)
2.  Search for **Git Graph**
3.  Install it

Now open your repo's folder in VS Code:

**File → Open Folder → GitPractice**

Open the Source Control sidebar (three circles with lines). In the top bar you'll see an icon with vertical lines and dots **View Git Graph**.

The other useful control here is the **Show Remote Branches** toggle to display or hide other developers' branches that exist on GitHub.

I recommend keeping a VS Code window open with Git Graph even if you code in another IDE. If you go to the top menu bar and click **Terminal → New Terminal** then you can get a bash window below to type in future Git commands.

Finally set up your Git identity:

```
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

</details>

---

<details>
  <summary id="Check-it-all-works">Check it all works</summary>

## Check it all works

In your cloned repo are a few files. Let's make a simple change and commit it.

### Typical workflow

-   Make a branch
-   Write code
-   Commit
-   Write more code
-   Commit
-   Repeat
-   Push
-   Open Pull Request

Note the differences to SVN here.

Firstly, we always work in a branch. These are lightweight, quick, and easy to make unlike SVN. They are not a new copy of the repo, but mark a jumping off point for a new set of changes to be made away from your important main/master branch.

Commits are purely to your local git instance. Many commits are made when working on a task.

Push is when you send your changes to GitHub. You can do this as often as you like, it will only update your current branch. The main branch will not be affected, and all your work in progress is then backed up on GitHub instead of solely on your hard drive.

Pull Request is the final step to merge your changes into main.

---

In the repo are some files. Go to `MathLib.cpp` and you can see the function is incomplete. We will fix it.

First we will checkout and move into a new branch:
```
git checkout -b MATH-0001_<Your name>_FixAddFunction

# e.g.
# git checkout -b MATH-0001_RichSteele_FixAddFunction
```

Change line 5 from `return 0;` to `return A + B;` and save. Next we will commit the change.

### Commit

A commit saves your changes *locally*. Commit early, commit often, and you won't ever risk losing work. You can and should commit multiple times per task. Get used to it. It is a brilliant safety net compared to one large bundled up commit like SVN.

Using VS Code:

1.  Make changes and save the file
2.  Open the Source Control panel
3.  Review changes before staging
4.  Stage files using the **+** icon
5.  Write a meaningful commit message
6.  Click the ✓ to commit

A good commit message is important. Avoid things like "WIP" or "fixed bug".

In step 3 above when using VS Code, clicking on each file will bring up a traditional diff. Use this opportunity to remove any unnecessary changes e.g. extra new lines or whitespace. You can do this in the opened diff view within VS Code.

CLI equivalent:

```
git diff
git add path/to/file
# or to stage everything
git add -A

git commit -m "My descriptive commit message"
```

Feel free to make another change and commit that too. You should be comfortable making multiple commits while on a task.

### Push

This sends your branch to GitHub:

```
git push
```

The first time, Git will tell you to set the upstream. This is the place where Git is trying to push your changes to. GitHub doesn't yet know about your new branch. Nicely though, it tells you what to type to fix this. Copy what it says and press Enter (instead of `--set-upstream` you can also use the shorthand `-u`).

```
git push -u origin <branchName>
```

After that, `git push` is enough.

Similar to commits, you should get used to pushing often. Keeping GitHub up to date with your changes has no downsides. If your computer dies overnight then everything is stored safely and securely on GitHub. It does not affect anyone else's branches, that only happens with Pull requests.

### Pull Request

A Pull Request (PR) asks to merge your changes into main. Often, if you are quick enough after pushing then GitHub will give you a notification about the branch and suggest that you pull request. Otherwise go to the repo on GitHub → switch to your branch → **New Pull Request**.

Give it:

-   A sensible title. This should be the Jira ticket ID and title.
-   A good description
   + If working from a jira ticket, add a link to the ticket here
   + If you have made good commit messages so far, this can often be a collection or summary of just those commit messages
-   Check the "Files changed" tab

Submit it. Now anyone can review it, comment, request changes, or approve. When working on project we can request reviewers on the PR page, word of mouth, or simply by seeing which PRs are currently pending. I have left a PR pending at https://github.com/Allen-Heath/GitPractice/pulls. Go there and leave a comment on it. Approve it if you think it's ready to merge in. To start a review go to the Files Changed tab on that pull request page. You can comment on any line by hovering over a line and clicking the blue `+` button, start a review, request changes, or approve with the green review button in the upper right.

PR review is normal and healthy. It is how quality is maintained.

Once approved by someone, it is your responsibility to merge in your own pull request. You will have recieved an email when your PR is approved with a link to the PR itself. Go there and click merge. Now main has your changes.

The branch you were working on has served it's purpose and you can delete it. After merging GitHub will prompt this for you.

```
# to remove just your local branch leaving the one on GitHub intact

git branch -d <BranchName>

# To remove both your local and upstream branch on GitHub

git branch -D <BranchName>
```

Note you cannot delete a branch that you are currently in, so create and move to a different one. Not `main`... Get in the habit of leaving that one alone.

Also, Git will warn you if you are about to delete a branch with unmerged changes. Which is brilliant and has saved many lives.

</details>

---

<details>
  <summary id="Updating">Updating</summary>

## Updating

Your local repo is not updated automatically. You will generally use either of two methods keep your local repo up to date.

You can use `git pull` to pull down any changes made to the branch you are currently in. Consider working on a feature that requires both Windows desktop work and Ubuntu VM work. You can push code changes on a branch from one machine, then pull down those changes from another without ever having to pull request into main. But, most often you will use it to keep your main branch up to date with the main branch on GitHub. Following this, you will have learned not to be currently in main so move into it now and pull down any changes:

```
git checkout main
git pull
git checkout <Whatever branch you were in before so you are not in main>

# if you have forgotten your other branch's name, list all local branches with

git branch
```

Now your main branch is up to date.

However your other existing branches have not been updated. You will have to manually update them yourself. Go into whatever development branch you need to update:

```
git checkout <Branch name>
git merge main
```

You can also fetch any changes made by anyone to the project's repo e.g. other developers' working branches, or the branch you would have pushed in the previous example from your other development machine.

```
git fetch --all
git checkout main
git merge origin/main
```

> Note: 'Origin' here is what Git calls the repo from which you have cloned. In this case, the Allen-Heath GitHub repo.
> Check this by entering `git remote -v`.
>
> Fetching does **not** update changed branches locally. It merely updates your local git instance's knowledge of the state of the remote branch. You will update your local code yourself.
> This is normal, safe, and will feel like second nature soon.

Now your `main` matches the canonical version.

Remember don't stay in `main`. Either create a new branch:

```
git checkout -b MyNewBranch
```

or update an existing one:

```
git checkout WorkingBranch
git merge main
```

Git is far better at merging than SVN. This is part of the reason that we are migrating to it. Merging will be a regular and easy process.

</details>

---

<details>
  <summary id="Branch-switching">Branch switching</summary>

## Branch switching

Creating and switching between branches is incredibly easy and useful with git. It allows you to make and save changes to files, then change to a different task with entirely different code changes if the first task becomes blocked, or you are required to switch to a different feature.

I'll walk through a quick demonstration.

Open your graph/tree visual representation to follow where your position in it changes.

First move to where your main branch is and checkout a new branch:
```
git checkout main
git checkout -b DEMO_HelloWorld
```

Open *StringLib.cpp* and add a comment in the constructor that says "Hello World!"
```
#include "StringLib.h"

StringLib::StringLib()
{
    // Hello World!
}
```

Save and commit the change as before. Notice in your graph view how the commit has been added at the top.

Move back to where your main branch is and checkout a new branch:
```
git checkout main
git checkout -b DEMO_FrenchHelloWorld
```

Notice the tree view. Your previous commit is still at the top, but your active highlighted position is now in the new branch at the same position as main.

As before add a comment to *StringLib.cpp* in the constructor that says "Bonjour le monde!"
```
#include "StringLib.h"

StringLib::StringLib()
{
    // Bonjour le monde!
}
```

Save and commit the change as before. Notice in your graph view how the commit has been added at the top, but on a seperate path from the HelloWorld branch, both branching from main.

With *StringLib.cpp* open, use git to switch back and forth between the branches you have just created. The file will change, the highlighted position in the tree view will change. It's quick, easy, and safe.

```
git checkout DEMO_HelloWorld

# See the file change to show "Hello World!"

git checkout DEMO_FrenchHelloWorld

# See the file change to show "Bonjour le monde!"
# Repeat as much as you like
```

These branches are now pointless so you can delete them as before.

> Get in the habit of regularly housekeeping your old branches. Although it is expected to have a few with experimental features, work in progress, or specific debug output in.
  
</details>

---

<details>
  <summary id="Submodules">Submodules</summary>

## Submodules

Our projects' architecture can be very complex. They often rely upon shared dependencies that span many projects e.g. AHNet. We do not want a different copy of this folder in every project that will inevitably become out of sync with other copies.

Instead we will use the concept of *submodules* to include that code. A submodule is **another repo** that **our repo** will include and pull down as well. You do not need to checkout each submodule as a new repo. Submodules that each project is dependant upon will be configured in the repo itself.

You will pull down required submodules with any relevant changes with this command:

```
git submodule update --init --recursive
```

Other than having to type this in, submodule use shouldn't affect you day to day.

However, if you are working on a task that spans across multiple submodules, then know that you will have to commit, push, and pull request to each corresponding repo e.g. dLive **and** AHNet. This is a *good thing*. It will make us aware of how our changes will potentially affect other dependant projects by highlighting the changes we are making to each repo. It should help mitigate accidental commits breaking other projects.

---

Let me know if you run into any problems.

Rich

</details>

---

<details>
  <summary id="Cheat-sheet">Cheat sheet</summary>

## Cheat sheet

There are many commands Git can use. But these are enough for anyone to use Git effectively. More complicated commands exist but you shouldn't need to use them. If something goes wrong and those functions are required then someone with experience should use them.

---

Show current status of your branch, e.g. changed or staged files:
```
git status
```

List all local branches:
```
git branch
```

Switch to an existing branch:
```
git checkout BRID-1234_MyName_MyBranchName
```

Create and switch to a new branch:
```
git checkout -b BRID-1235_MyName_MyNewBranchName
```

Update your repo:
```
git fetch --all
git checkout main
git merge origin/main

# Don't stay in main

git checkout BRID-1234_MyName_MyBranchName

# Bring your branch up to date

git merge main
```

pull down changes for my current branch, remote to local
```
git pull
```

Stage files (although I recommend using a GUI interface):
```
git add path/to/file
```

Commit:
```
git commit -m "This is my sensible commit message"
```

Push:
```
git push
```

</details>

---
<details>
  <summary id="Advanced-comparison">Advanced comparison</summary>

## Git vs SVN Command Comparison

| Action / Purpose                     | Git Command                                   | SVN Command                                |
|--------------------------------------|-----------------------------------------------|--------------------------------------------|
| Check out / clone a repository       | `git clone <url>`                             | `svn checkout <url>`                       |
| See current status                   | `git status`                                  | `svn status`                               |
| Add a file                           | `git add <file>`                              | `svn add <file>`                           |
| Commit changes                       | `git commit -m "message"`                     | `svn commit -m "message"` (or `svn ci`)    |
| View history                         | `git log`                                     | `svn log`                                  |
| Update from remote                   | `git pull`                                    | `svn update` (or `svn up`)                 |
| Push changes                         | `git push`                                    | *(N/A SVN commits go directly to server)*  |
| Revert file to last commit           | `git checkout -- <file>`                      | `svn revert <file>`                        |
| Show differences                     | `git diff`                                    | `svn diff`                                 |
| Create a branch                      | `git checkout -b <branch>`                    | `svn copy trunk branches/<branch>`         |
| Switch branch                        | `git checkout <branch>`                       | `svn switch <branch-url>`                  |
| Merge a branch                       | `git merge <branch>`                          | `svn merge <branch-url>`                   |
| View branches                        | `git branch`                                  | `svn list <repo>/branches`                 |
| Delete a branch                      | `git branch -d <branch>`                      | `svn delete <repo>/branches/<branch>`      |
| View remote repos                    | `git remote`                                  | *(N/A SVN uses a single central repo)*     |
| Stash changes                        | `git stash`                                   | *(N/A no stash in SVN)*                    |
| Undo last commit (keep changes)      | `git reset --soft HEAD~1`                     | *(SVN does not support this. Only reverse commits)* |
| Undo last commit (discard changes)   | `git reset --hard HEAD~1`                     | `svn merge -c -REV .` then commit          |

^ Be very careful with that last one. It will throw away committed work. Don't use it. I left it there so you know to avoid it.

Similarly, Git will generally reject a command that will cause a conflict or act destructively. `-f` may force that change but please don't use this. There is likely a conflict somewhere that requires attention. Don't force changes.

(Thanks for the table ChatGPT)

</details>
